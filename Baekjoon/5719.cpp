#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int n, m, s, d;
vector<pair<int, pair<bool, int>>> edges[501];
vector<int> parent[501];

int dist[501];

int dijkstra() {
  for (int i = 0; i < n; i++) {
    dist[i] = 1e9;
  }
  dist[s] = 0;

  priority_queue<pair<int, int>> q;
  q.push({-0, s});
  while (!q.empty()) {
    int d = -q.top().first;
    int cur = q.top().second;
    q.pop();

    if (d > dist[cur]) continue;

    for (auto &x : edges[cur]) {
      if (x.second.first && dist[x.first] > dist[cur] + x.second.second) {
        dist[x.first] = dist[cur] + x.second.second;
        parent[x.first].clear();
        parent[x.first].push_back(cur);
        q.push({-dist[x.first], x.first});
      }

      if (x.second.first && dist[x.first] == dist[cur] + x.second.second) {
        parent[x.first].push_back(cur);
      }
    }
  }

  return dist[d];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  while (n && m) {
    cin >> s >> d;
    for (int i = 0; i < n; i++) {
      edges[i].clear();
      parent[i].clear();
    }

    for (int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      edges[u].push_back({v, {true, p}});
    }

    dijkstra();

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(d);
    visited[d] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto &p : parent[cur]) {

        for (auto &y : edges[p]) {
          if (y.first == cur) {
            y.second.first = false;
          }
        }

        if (!visited[p]) {
          visited[p] = true;
          q.push(p);
        }
      }
    }

    dijkstra();
    cout << (dist[d] == 1e9 ? -1 : dist[d]) << nl;
    cin >> n >> m;
  }

  return 0;
}

