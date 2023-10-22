#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int n, l, timer;
vector<vector<int>> adj;
vector<int> p;

vector<int> tin;
vector<int> tout;
vector<vector<int>> up;

void dfs(int v, int parent) {
  tin[v] = ++timer;

  up[v][0] = parent;
  for (int i = 1; i <= l; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }

  for (int u : adj[v]) {
    if (u != parent) {
      dfs(u, v);
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    l = ceil(log2(n));
    timer = 0;
    tin.resize(n + 1);
    tout.resize(n + 1);
    up.assign(n + 1, vector<int>(l + 1));
    p.resize(n + 1);
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
      p[i] = -1;
    }

    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      p[b] = a;
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
      if (p[i] == -1) {
        root = i;
      }
    }
    dfs(root, root);

    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << nl;
  }

  return 0;
}
