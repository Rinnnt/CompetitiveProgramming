#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

int tstart[100001];
int tend[100001];
int children[100001];
int f[100001][25];
vector<int> edges[100001];
int timer = -1;

int dfs(int cur, int p) {
  tstart[cur] = ++timer;
  children[cur] = 1;

  f[cur][0] = p;
  for (int i = 1; i < 25; i++)
    f[cur][i] = f[f[cur][i - 1]][i - 1];

  for (auto x : edges[cur])
    if (x != p)
      children[cur] += dfs(x, cur);
  tend[cur] = timer;
  return children[cur];
}

bool is_ancestor(int a, int b) {
  return tstart[a] <= tstart[b] && tend[a] >= tend[b];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    timer = 0;

    int n, q, r;
    cin >> n >> q >> r;

    for (int j = 1; j <= n; j++)
      edges[j].clear();

    for (int j = 0; j < n - 1; j++) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    dfs(r, r);

    cout << "Case #" << i << ":" << nl;
    for (int j = 0; j < q; j++) {
      int s, u;
      cin >> s >> u;
      if (s == 0) {
        r = u;
      } else {
        if (u == r) {
          cout << n << nl;
        } else if (!is_ancestor(u, r)) {
          cout << children[u] << nl;
        } else {
          int cr = r;
          for (int k = 24; k >= 0; k--)
            if (!is_ancestor(f[cr][k], u))
              cr = f[cr][k];
          cout << n - children[cr] << nl;
        }
      }

    }
  }

  return 0;
}
