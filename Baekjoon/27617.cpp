#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

vector<pair<int, int>> edges[101];
int dist[101] = {};
bool considered[101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 101; i++) {
    dist[i] = 1e9;
  }

  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int total = 0;

  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    edges[u].push_back({v, l});
    edges[v].push_back({u, l});
    total += l;
  }

  priority_queue<pair<int, int>> q;
  q.push({0, a});
  dist[a] = 0;
  while (!q.empty()) {
    int d = -q.top().first;
    int cur = q.top().second;
    q.pop();

    if (cur == b) {
      break;
    }

    if (d > dist[cur]) {
      continue;
    }

    for (auto x : edges[cur]) {
      if (d + x.second < dist[x.first]) {
        dist[x.first] = d + x.second;
        q.push({-dist[x.first], x.first});
      }
    }
  }

  queue<int> t;
  t.push(b);
  considered[b] = true;
  while (!t.empty()) {
    int cur = t.front();
    t.pop();

    for (auto x : edges[cur]) {
      if (dist[x.first] == dist[cur] - x.second) {
        total -= x.second;
        considered[x.first] = true;
        t.push(x.first);
      }
    }
  }

  cout << total;


}
