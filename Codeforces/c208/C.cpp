#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, m;
vector<int> edges[101];
ll dist[101][101];
ll cnt[101][2];

ll dfs(int cur, int idx) {
  if (cnt[cur][idx] != -1) return cnt[cur][idx];

  int end = (idx == 0 ? 1 : n);

  if (cur == end) return cnt[cur][idx] = 1;

  cnt[cur][idx] = 0;
  if (dist[1][cur] + dist[cur][n] == dist[1][n]) {
    for (auto n : edges[cur]) {
      if (dist[n][end] == dist[cur][end] - 1) {
        cnt[cur][idx] += dfs(n, idx);
      }
    }
  }
  return cnt[cur][idx];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 1; i < 101; i++) {
    cnt[i][0] = -1;
    cnt[i][1] = -1;
    for (int j = 1; j < 101; j++) {
      dist[i][j] = (i == j ? 0 : 1e9);
    }
  }

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
    dist[u][v] = 1;
    dist[v][u] = 1;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for (int i = 1; i <= n; i++)
    dfs(i, 0);

  for (int i = 1; i <= n; i++)
    dfs(i, 1);

  ll maxpaths = 0;
  for (int i = 1; i <= n; i++) {
    ll paths = 1LL * cnt[i][0] * cnt[i][1];
    if (i != 1 && i != n) {
      paths *= 2LL;
    }
    maxpaths = max(maxpaths, paths);
  }
  ll paths = cnt[n][0];

  ld average = ((ld)maxpaths) / ((ld)paths);

  cout << fixed << setprecision(15) << average << nl;

  return 0;
}

