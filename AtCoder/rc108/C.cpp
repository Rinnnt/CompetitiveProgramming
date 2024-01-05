#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, m;
vector<pii> edges[100001];
int color[100001];

void dfs(int cur, int c) {
  color[cur] = c;
  for (auto x : edges[cur]) {
    if (color[x.first] == 1e9) {
      if (x.second == c) {
        dfs(x.first, (c == n ? 1 : c + 1));
      } else {
        dfs(x.first, x.second);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    color[i] = 1e9;

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edges[u].push_back({v, c});
    edges[v].push_back({u, c});
  }

  dfs(1, 1);

  for (int i = 1; i <= n; i++)
    cout << color[i] << nl;

  return 0;
}

