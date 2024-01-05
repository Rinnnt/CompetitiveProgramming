#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<pii> edges[100001];
ll x[100001];

ll mn = 1e15;
ll mx = -1e15;

bool dfs(int v, ll pos) {
  x[v] = pos;
  mn = min(mn, x[v]);
  mx = max(mx, x[v]);

  for (auto u : edges[v]) {
    if (x[u.first] == 1e15)
      if (!dfs(u.first, pos + u.second)) return false;
    if (x[u.first] != x[v] + u.second) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    edges[u].push_back({v, d});
    edges[v].push_back({u, -d});
  }

  for (int i = 1; i <= n; i++) {
    x[i] = 1e15;
  }

  for (int i = 1; i <= n; i++) {
    if (x[i] == 1e15) {
      mn = 1e15;
      mx = -1e15;
      if (!dfs(i, 0LL) || mx - mn > 1e9) {
        cout << "No" << nl;
        return 0;
      }
    }
  }

  cout << "Yes" << nl;

  return 0;
}

