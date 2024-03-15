#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

bool visited[200001];
ll pos[200001];
vector<pii> edges[200001];
bool valid = true;

void dfs(int cur) {
  visited[cur] = true;

  for (auto [n, c] : edges[cur]) {
    if (visited[n]) {
      if (pos[cur] + c != pos[n])
        valid = false;
    } else {
      pos[n] = pos[cur] + c;
      dfs(n);
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      valid = true;
      for (int i = 0; i < 200001; i++) {
        visited[i] = false;
        pos[i] = 0;
        edges[i].clear();
      }

      int n, m;
      cin >> n >> m;

      for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({b, -d});
        edges[b].push_back({a, d});
      }

      for (int i = 1; i <= n; i++) {
        if (!visited[i])
          dfs(i);
      }

      if (valid)
        cout << "YES" << nl;
      else
        cout << "NO" << nl;

    }

    return 0;
}
