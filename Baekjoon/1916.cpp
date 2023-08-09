#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[1001];
ll dist[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    dist[i] = 1e18;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
  }

  int s, e;
  cin >> s >> e;

  priority_queue<pair<int, int>> q;
  q.push({0, s});
  dist[s] = 0;
  while (!q.empty()) {
    int d = -1 * q.top().first;
    int cur = q.top().second;
    q.pop();
    if (cur == e) {
      break;
    }
    for (auto x : edges[cur]) {
      if (d + x.second < dist[x.first]) {
        dist[x.first] = d + x.second;
        q.push({-1 * dist[x.first], x.first});
      }
    }
  }

  cout << dist[e];

  return 0;
}
