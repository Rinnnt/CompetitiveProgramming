#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[300001];

int maxd = -1;
int node = -1;
int diameter = -1;
set<int> vs;

void dfs(int c, int p, int d) {
  if (d > maxd) {
    maxd = d;
    node = c;
  }

  for (auto n : edges[c])
    if (n != p)
      dfs(n, c, d + 1);
}

void dfs2(int c, int p, int d) {
  if (d == diameter) vs.insert(c);

  for (auto n : edges[c])
    if (n != p)
      dfs2(n, c, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    dfs(1, 0, 0);

    int a = node;
    maxd = -1;
    node = -1;
    dfs(a, 0, 0);

    diameter = maxd;
    int b = node;

    dfs2(a, 0, 0);
    dfs2(b, 0, 0);

    for (int i = 1; i <= n; i++) {
      if (vs.count(i)) {
        cout << diameter + 1 << nl;
      } else {
        cout << diameter << nl;
      }
    }

    return 0;
}
