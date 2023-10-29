#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

vector<int> roots;
vector<vector<int>> adj_scc;

vector<int> atm;
vector<bool> restaurant;
vector<ll> dp;

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

ll solve(int v) {
  if (dp[v] != -1e16)
    return dp[v];

  ll ans = -1e15;
  if (restaurant[v]) {
    ans = atm[v];
  }
  for (auto u : adj_scc[v]) {
    ans = max(ans, atm[v] + solve(u));
  }

  return dp[v] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

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

  atm.resize(n + 1);
  restaurant.assign(n + 1, false);

  for (int i = 1; i <= n; i++)
    cin >> atm[i];

  int s, p;
  cin >> s >> p;

  for (int i = 0; i < p; i++) {
    int x;
    cin >> x;
    restaurant[x] = true;
  }

  used.assign(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!used[i])
      dfs1(i);


  used.assign(n + 1, false);
  reverse(order.begin(), order.end());

  roots.assign(n + 1, 0);
  adj_scc.assign(n + 1, vector<int>());

  for (auto v : order) {
    if (!used[v]) {
      dfs2(v);

      int root = component.front();
      for (auto u : component) {
        roots[u] = root;
        restaurant[root] = restaurant[root] || restaurant[u];
        if (root != u) {
          atm[root] += atm[u];
        }
      }

      component.clear();
    }
  }

  for (int v = 1; v <= n; v++) {
    for (auto u : adj[v]) {
      int root_v = roots[v];
      int root_u = roots[u];

      if (root_u != root_v) {
        adj_scc[root_v].push_back(root_u);
      }
    }
  }

  dp.assign(n + 1, -1e16);

  cout << solve(roots[s]) << nl;

  return 0;
}

