#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF 1e9

int n, p;
int N;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
  parent.resize(N);
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t) {
          return new_flow;
        }
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(N, -1);
  int new_flow;

  while ((new_flow = bfs(s, t, parent))) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> p;
  N = 2 * n + 1;
  capacity.assign(N, vector<int>(N, 0));
  adj.assign(N, vector<int>());

  for (int i = 1; i <= n; i++) {
    capacity[i + n][i] = 1;
    adj[i + n].push_back(i);
    adj[i].push_back(i + n);
  }

  for (int i = 0; i < p; i++) {
    int u, v;
    cin >> u >> v;
    if (u == 1 || u == 2) {
      capacity[u][v + n] = 1;
      capacity[v][u] = 1;
      adj[u].push_back(v + n);
      adj[v + n].push_back(u);
      adj[v].push_back(u);
      adj[u].push_back(v);
    } else if (v == 1 || v == 2) {
      capacity[u][v] = 1;
      capacity[v][u + n] = 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
      adj[v].push_back(u + n);
      adj[u + n].push_back(v);
    } else {
      capacity[u][v + n] = 1;
      capacity[v][u + n] = 1;
      adj[u].push_back(v + n);
      adj[v + n].push_back(u);
      adj[v].push_back(u + n);
      adj[u + n].push_back(v);
    }
  }

  cout << maxflow(1, 2) << nl;

  return 0;
}
