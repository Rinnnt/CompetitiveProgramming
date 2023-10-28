#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, l, timer;
vector<vector<pair<int, int>>> adj;

vector<int> tin;
vector<int> tout;
vector<vector<int>> up;
vector<vector<int>> dist;

void dfs(int v, int p, int d) {
  tin[v] = ++timer;

  up[v][0] = p;
  dist[v][0] = d;
  for (int i = 1; i <= l; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    dist[v][i] = dist[v][i - 1] + dist[up[v][i - 1]][i - 1];
  }

  for (auto u : adj[v]) {
    if (u.first != p) {
      dfs(u.first, v, u.second);
    }
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  if (is_ancestor(v, u)) {
    return v;
  }
  for (int i = l; i >= 0; i--) {
    if (!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }

  return up[u][0];
}

int lca_dist(int u, int v) {
  int lc = lca(u, v);

  int res = 0;
  if (u != lc) {
    for (int i = l; i >= 0; i--) {
      if (!is_ancestor(up[u][i], lc)) {
        res += dist[u][i];
        u = up[u][i];
      }
    }
    res += dist[u][0];
  }

  if (v != lc) {
    for (int i = l; i >= 0; i--) {
      if (!is_ancestor(up[v][i], lc)) {
        res += dist[v][i];
        v = up[v][i];
      }
    }
    res += dist[v][0];
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  l = ceil(log2(n));
  timer = 0;
  tin.resize(n + 1);
  tout.resize(n + 1);
  up.assign(n + 1, vector<int>(l + 1));
  dist.assign(n + 1, vector<int>(l + 1));
  adj.assign(n + 1, vector<pair<int, int>>());

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  dfs(1, 1, 0);

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cout << lca_dist(u, v) << nl;
  }

  return 0;
}

