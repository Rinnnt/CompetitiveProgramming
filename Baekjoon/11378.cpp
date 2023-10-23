#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF 1e9

int n, m, k;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
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
  vector<int> parent(n + m + 3);
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

  cin >> n >> m >> k;
  capacity.assign(n + m + 3, vector<int>(n + m + 3, 0));
  adj.assign(n + m + 3, vector<int>());

  for (int i = 1; i <= n; i++) {
    int j;
    cin >> j;
    while (j--) {
      int v;
      cin >> v;
      capacity[i][n + v] = 1;
      adj[i].push_back(n + v);
      adj[n + v].push_back(i);
    }
    adj[n + m + 1].push_back(i);
    adj[i].push_back(n + m + 1);
    capacity[n + m + 1][i] = 1;
  }

  for (int j = n + 1; j <= n + m; j++) {
    adj[n + m + 2].push_back(j);
    adj[j].push_back(n + m + 2);
    capacity[j][n + m + 2] = 1;
  }

  int ans = maxflow(n + m + 1, n + m + 2);

  for (int j = n + 1; j <= n + m; j++) {
    if (k && capacity[j][n + m + 2] && adj[j].size() > 1) {
      k--;
      ans++;
    }
  }

  cout << ans << nl;

  return 0;
}
