#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[100005];

pii dfs(int cur, int p, int x) {
  int components = 0;
  int nodes = 1;
  for (auto n : edges[cur]) {
    if (n != p) {
      pii t = dfs(n, cur, x);
      components += t.first;
      nodes += t.second;
    }
  }
  if (nodes >= x) {
    components += 1;
    nodes = 0;
  }
  return {components, nodes};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;

      for (int i = 1; i <= n; i++) {
        edges[i].clear();
      }

      for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
      }

      int l = 1;
      int r = n;

      while (l + 1 < r) {
        int mid = (l + r) / 2;

        if (dfs(1, -1, mid).first > k) {
          l = mid;
        } else {
          r = mid;
        }
      }

      cout << l << nl;
    }

    return 0;
}
