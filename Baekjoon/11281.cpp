#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<vector<int>> adj, adj_rev;
vector<int> used;
vector<int> order;
vector<int> comp;
int comp_idx = 0;

void dfs(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u])
      dfs(u);

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  comp[v] = comp_idx;

  for (auto u : adj_rev[v])
    if (!used[u])
      dfs2(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  int N = 2 * n + 1;

  adj.assign(N, vector<int>());
  adj_rev.assign(N, vector<int>());

  for (int i = 0; i < m; i++) {
    int a, b, na, nb;
    cin >> a >> b;
    if (a > 0) {
      a = 2 * a - 1;
      na = a + 1;
    } else {
      a = -2 * a;
      na = a - 1;
    }
    if (b > 0) {
      b = 2 * b - 1;
      nb = b + 1;
    } else {
      b = -2 * b;
      nb = b - 1;
    }
    adj[na].push_back(b);
    adj[nb].push_back(a);
    adj_rev[b].push_back(na);
    adj_rev[a].push_back(nb);
  }


  used.assign(N, false);
  order.clear();

  for (int i = 1; i < N; i++)
    if (!used[i])
      dfs(i);

  used.assign(N, false);
  comp.resize(N);
  for (int i = 0; i < N; i++) comp[i] = i;
  reverse(order.begin(), order.end());

  for (auto v : order) {
    if (!used[v])
      comp_idx++, dfs2(v);
  }

  bool pos = true;
  vector<bool> assign(n + 1);
  for (int i = 1; i <= n; i++) {
    assign[i] = comp[2 * i - 1] > comp[2 * i];
    if (comp[2 * i] == comp[2 * i - 1]) {
      pos = false;
      break;
    }
  }

  cout << pos << nl;
  if (pos)
    for (int i = 1; i <= n; i++)
      cout << assign[i] << " ";

  return 0;
}

