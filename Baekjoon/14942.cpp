#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int p[100001];
int f[100001][25];
int r[100001][25];
vector<pair<int, int>> edges[100001];

void dfs(int cur, int parent, int w) {
  f[cur][0] = parent;
  r[cur][0] = w;

  for (int i = 1; i < 25; i++) {
    f[cur][i] = f[f[cur][i - 1]][i - 1];
    r[cur][i] = r[cur][i - 1] + r[f[cur][i - 1]][i - 1];
  }

  for (auto x : edges[cur])
    if (x.first != parent)
      dfs(x.first, cur, x.second);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> p[i];

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  dfs(1, 1, 0);

  for (int i = 1; i <= n; i++) {
    int cur = i;
    int energy = p[i];
    for (int k = 24; k >= 0; k--)
      if (energy >= r[cur][k])
        energy -= r[cur][k], cur = f[cur][k];
    cout << cur << nl;
  }

  return 0;
}
