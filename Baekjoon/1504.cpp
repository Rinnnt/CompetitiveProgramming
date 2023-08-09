#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[801];
ll dist1[801];
ll dist2[801];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, e;
  cin >> n >> e;
  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    dist1[i] = 1e12;
    dist2[i] = 1e12;
  }

  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  int v1, v2;
  cin >> v1 >> v2;

  priority_queue<pair<ll, int>> q;
  q.push({0, v1});
  dist1[v1] = 0;
  while (!q.empty()) {
    int d = -1 * q.top().first;
    int cur = q.top().second;
    q.pop();
    for (auto x : edges[cur]) {
      if (d + x.second < dist1[x.first]) {
        dist1[x.first] = d + x.second;
        q.push({-1 * dist1[x.first], x.first});
      }
    }
  }

  q.push({0, v2});
  dist2[v2] = 0;
  while (!q.empty()) {
    int d = -1 * q.top().first;
    int cur = q.top().second;
    q.pop();
    for (auto x : edges[cur]) {
      if (d + x.second < dist2[x.first]) {
        dist2[x.first] = d + x.second;
        q.push({-1 * dist2[x.first], x.first});
      }
    }
  }

  ll ans = min(dist1[1] + dist1[v2] + dist2[n], dist2[1] + dist2[v1] + dist1[n]);
  cout << (ans < 1e12 ? ans : -1);

  return 0;
}
