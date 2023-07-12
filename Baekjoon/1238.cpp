#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dist[1001];
int rdist[1001];
vector<pair<int, int>> edges[1001];
vector<pair<int, int>> redges[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    int s, e, t;
    cin >> s >> e >> t;
    edges[s].push_back({e, t});
    redges[e].push_back({s, t});
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
    rdist[i] = 1e9;
  }
  dist[x] = 0;
  rdist[x] = 0;

  priority_queue<pair<int, int>> q;
  q.push({0, x});
  while (!q.empty()) {
    pair<int, int> cur = q.top();
    q.pop();
    for (auto x : edges[cur.second]) {
      if (-1 * cur.first + x.second < dist[x.first]) {
        dist[x.first] = -1 * cur.first + x.second;
        q.push({-1 * dist[x.first], x.first});
      }
    }
  }

  q.push({0, x});
  while (!q.empty()) {
    pair<int, int> cur = q.top();
    q.pop();
    for (auto x : redges[cur.second]) {
      if (-1 * cur.first + x.second < rdist[x.first]) {
        rdist[x.first] = -1 * cur.first + x.second;
        q.push({-1 * rdist[x.first], x.first});
      }
    }
  }

  int maxtime = 0;
  for (int i = 1; i <= n; i++) {
    maxtime = max(maxtime, dist[i] + rdist[i]);
  }
  cout << maxtime;

  return 0;
}
