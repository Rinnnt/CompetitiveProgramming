#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<pii> edges[101];

int dfs(int c, int p) {
  int res = 0;
  for (auto n : edges[c]) {
    if (n.first != p) {
      res = max(res, dfs(n.first, c) + n.second);
    }
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      edges[u].push_back({v, c});
      edges[v].push_back({u, c});
    }

    cout << dfs(0, -1) << nl;

    return 0;
}
