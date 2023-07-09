#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < n; i++) {
    edges[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  set<int> visited;
  queue<int> q;
  q.push(1);
  visited.insert(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto x : edges[cur]) {
      if (!visited.count(x)) {
        q.push(x);
        visited.insert(x);
      }
    }
  }

  cout << visited.size() - 1;
}
