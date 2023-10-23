#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF 1e9

int n, p;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
  parent.resize(n + 1);
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
  vector<int> parent(n + 1, -1);
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
  capacity.assign(n + 1, vector<int>(n + 1, 0));
  adj.assign(n + 1, vector<int>());

  for (int i = 0; i < p; i++) {
    int u, v;
    cin >> u >> v;
    capacity[u][v] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << maxflow(1, 2);

  return 0;
}
