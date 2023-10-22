#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v]) {
    if (!used[u]) {
      dfs1(u);
    }
  }

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v]) {
    if (!used[u]) {
      dfs2(u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, e;
  cin >> n >> e;

  adj.assign(n + 1, vector<int>());
  adj_rev.assign(n + 1, vector<int>());

  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
  }

  used.assign(n + 1, false);

  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs1(i);
    }
  }

  used.assign(n + 1, false);
  reverse(order.begin(), order.end());

  vector<vector<int>> comps;
  vector<int> comp(n + 1);
  for (auto  v : order) {
    if (!used[v]) {
      dfs2(v);

      sort(component.begin(), component.end());

      for (auto x : component) {
        comp[x] = comps.size();
      }
      comps.push_back(component);
      component.clear();
    }
  }

  used.assign(n + 1, false);

  cout << comps.size() << nl;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      for (auto x : comps[comp[i]]) {
        cout << x << " ";
        used[x] = true;
      }
      cout << "-1" << nl;
    }
  }

  return 0;
}
