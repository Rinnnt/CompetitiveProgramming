#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> edges[1001];
ll s[1001];
ll dist[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, m;
      cin >> n >> m;
      for (int i = 0; i < n; i++) {
        edges[i].clear();
        for (int j = 1; j <= 1000; j++) {
          dist[i][j] = 1e15;
        }
      }

      for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
      }
      for (int i = 0; i < n; i++) {
        cin >> s[i];
      }

      priority_queue<pll> q;
      q.push({-0, 0 * 1001 + s[0]});
      dist[0][s[0]] = 0;
      while (!q.empty()) {
        ll d = -q.top().first;
        ll c = q.top().second;
        q.pop();
        ll cn = c / 1001;
        ll cs = c % 1001;
        for (auto x : edges[cn]) {
          ll ncs = min(cs, s[x.first]);
          if (dist[x.first][ncs] > d + cs * 1LL * x.second) {
            dist[x.first][ncs] = d + cs  * 1LL * x.second;
            q.push({-dist[x.first][ncs], x.first * 1001 + ncs});
          }
        }
      }

      ll ans = 1e15;
      for (int i = 1; i <= 1000; i++) {
        ans = min(ans, dist[n - 1][i]);
      }

      cout << ans << nl;
    }

    return 0;
}
