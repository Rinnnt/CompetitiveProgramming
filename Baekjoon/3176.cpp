#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int n, l, timer;
vector<vector<pair<int, int>>> adj;

vector<int> tin;
vector<int> tout;
vector<vector<int>> up;
vector<vector<int>> minr;
vector<vector<int>> maxr;

void dfs(int v, int p, int d) {
  tin[v] = ++timer;

  up[v][0] = p;
  minr[v][0] = d;
  maxr[v][0] = d;
  for (int i = 1; i <= l; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    minr[v][i] = min(minr[v][i - 1], minr[up[v][i - 1]][i - 1]);
    maxr[v][i] = max(maxr[v][i - 1], maxr[up[v][i - 1]][i - 1]);
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

pair<int, pair<int, int>> lca(int u, int v) {
  if (is_ancestor(u, v)) {
    int minroad = 1e9;
    int maxroad = -1;
    for (int i = l; i >= 0; i--) {
      if (!is_ancestor(up[v][i], u)) {
        minroad = min(minroad, minr[v][i]);
        maxroad = max(maxroad, maxr[v][i]);
        v = up[v][i];
      }
    }
    minroad = min(minroad, minr[v][0]);
    maxroad = max(maxroad, maxr[v][0]);
    return {u, {minroad, maxroad}};
  }
  if (is_ancestor(v, u)) {
    int minroad = 1e9;
    int maxroad = -1;
    for (int i = l; i >= 0; i--) {
      if (!is_ancestor(up[u][i], v)) {
        minroad = min(minroad, minr[u][i]);
        maxroad = max(maxroad, maxr[u][i]);
        u = up[u][i];
      }
    }
    minroad = min(minroad, minr[u][0]);
    maxroad = max(maxroad, maxr[u][0]);
    return {v, {minroad, maxroad}};
  }
  int minroad = 1e9;
  int maxroad = -1;
  int tu = u;
  for (int i = l; i >= 0; i--) {
    if (!is_ancestor(up[tu][i], v)) {
      minroad = min(minroad, minr[tu][i]);
      maxroad = max(maxroad, maxr[tu][i]);
      tu = up[tu][i];
    }
  }
  minroad = min(minroad, minr[tu][0]);
  maxroad = max(maxroad, maxr[tu][0]);
  int tv = v;
  for (int i = l; i >= 0; i--) {
    if (!is_ancestor(up[tv][i], u)) {
      minroad = min(minroad, minr[tv][i]);
      maxroad = max(maxroad, maxr[tv][i]);
      tv = up[tv][i];
    }
  }
  minroad = min(minroad, minr[tv][0]);
  maxroad = max(maxroad, maxr[tv][0]);

  return {up[tv][0], {minroad, maxroad}};
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
  minr.assign(n + 1, vector<int>(l + 1));
  maxr.assign(n + 1, vector<int>(l + 1));
  adj.assign(n + 1, vector<pair<int, int>>());

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  dfs(1, 1, -10000);

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    pair<int, int> res = lca(u, v).second;
    cout << res.first << " " << res.second << nl;
  }

  return 0;
}
