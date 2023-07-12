#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[20001];
int dist[20001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int v, e, k;
  cin >> v >> e >> k;
  for (int i = 1; i <= v; i++) {
    edges[i].clear();
    dist[i] = 1e9;
  }
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
  }

  priority_queue<pair<int, int>> q;
  q.push({0, k});
  dist[k] = 0;
  while (!q.empty()) {
    int c = q.top().second;
    int d = -1 * q.top().first;
    q.pop();
    if (d > dist[c]) {
      continue;
    }
    for (auto x : edges[c]) {
      if (d + x.second < dist[x.first]) {
        dist[x.first] = d + x.second;
        q.push({-1 * dist[x.first], x.first});
      }
    }
  }

  for (int i = 1;  i <= v; i++) {
    if (dist[i] == 1e9) {
      cout << "INF" << nl;
    } else {
      cout << dist[i] << nl;
    }
  }

  return 0;
}
