#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, a, b;
bool pos;
vector<pii> edges[100001];
set<int> xs;

void dfs(int cur, int p, int x) {
  for (auto [n, c] : edges[cur]) {
    if (n != p) {
      xs.insert(x ^ c);
      dfs(n, cur, x ^ c);
    }
  }
}

void dfs2(int cur, int p, int x) {
  if (xs.count(x)) pos = true;
  for (auto [n, c] : edges[cur])
    if (n != p && n != b)
      dfs2(n, cur, x ^ c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      pos = false;
      xs.clear();
      for (int i = 0; i < 100001; i++)
        edges[i].clear();

      cin >> n >> a >> b;

      for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
      }

      dfs(b, -1, 0);

      dfs2(a, -1, 0);

      if (pos) cout << "YES" << nl;
      else cout << "NO" << nl;
    }

    return 0;
}
