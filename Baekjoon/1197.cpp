#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[10001];
bool visited[10001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(1);

  int n, e;
  cin >> n >> e;

  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    visited[i] = false;
  }

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  priority_queue<pair<int, int>> q;
  visited[1] = true;
  for (auto x : edges[1]) {
    q.push({-x.second, x.first});
  }

  int ans = 0;
  while (!q.empty()) {
    int c = q.top().second;
    int d = -1 * q.top().first;
    q.pop();
    if (!visited[c]) {
      visited[c] = true;
      ans += d;
      for (auto x : edges[c]) {
        q.push({-x.second, x.first});
      }
    }
  }

  cout << ans;

  return 0;
}
