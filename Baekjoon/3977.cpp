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

    adj.assign(n, vector<int>());
    adj_rev.assign(n, vector<int>());
    order.clear();
    component.clear();

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj_rev[v].push_back(u);
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++)
      if (!used[i])
        dfs1(i);


    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n);
    vector<int> start_component;

    for (auto v : order) {
      if (!used[v]) {
        dfs2(v);

        int root = component.front();
        for (auto u : component) roots[u] = root;
        root_nodes.push_back(root);
        if (!start_component.size())
          start_component = component;

        component.clear();
      }
    }

    vector<int> indegree(n, 0);

    for (int v = 0; v < n; v++) {
      for (auto u : adj[v]) {
        int root_v = roots[v];
        int root_u = roots[u];

        if (root_u != root_v) {
          adj_scc[root_v].push_back(root_u);
          indegree[root_u]++;
        }
      }
    }

    int num_start = 0;
    for (auto root : root_nodes)
      if (!indegree[root])
        num_start++;

    sort(start_component.begin(), start_component.end());
    if (num_start != 1)
      cout << "Confused" << nl;
    else
      for (auto u : start_component)
        cout << u << nl;
    cout << nl;
  }

  return 0;
}

