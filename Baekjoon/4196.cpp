#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u])
      dfs1(u);

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v])
    if (!used[u])
      dfs2(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    adj_rev.assign(n + 1, vector<int>());
    order.clear();
    component.clear();

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj_rev[v].push_back(u);
    }

    used.assign(n, false);
    for (int i = 1; i <= n; i++)
      if (!used[i])
        dfs1(i);


    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n + 1, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n + 1);

    for (auto v : order) {
      if (!used[v]) {
        dfs2(v);

        int root = component.front();
        for (auto u : component) roots[u] = root;
        root_nodes.push_back(root);

        component.clear();
      }
    }

    vector<int> indegree(n + 1, 0);

    for (int v = 1; v <= n; v++) {
      for (auto u : adj[v]) {
        int root_v = roots[v];
        int root_u = roots[u];

        if (root_u != root_v) {
          adj_scc[root_v].push_back(root_u);
          indegree[root_u]++;
        }

      }
    }

    int ans = 0;
    for (auto root : root_nodes)
      if (!indegree[root])
        ans++;


    cout << ans << nl;
  }


  return 0;
}

