#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[10001];
int tin[10001] = {};
int low[10001] = {};
bool visited[10001];
int timer = 0;
set<int> articulation_points;

void dfs(int cur, int parent) {
  visited[cur] = true;
  tin[cur] = low[cur] = ++timer;
  int children = 0;

  for (auto x : edges[cur]) {
    if (!visited[x]) {
      dfs(x, cur);
      children++;
      low[cur] = min(low[cur], low[x]);
      if (low[x] >= tin[cur] && parent != -1) {
        articulation_points.insert(cur);
      }
    } else if (visited[x] && x != parent) {
      low[cur] = min(low[cur], tin[x]);
    }
  }

  if (parent == -1 && children > 1) {
    articulation_points.insert(cur);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int v, e;
  cin >> v >> e;

  articulation_points.clear();
  for (int i = 1; i <= v; i++) {
    edges[i].clear();
    visited[i] = false;
  }

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (int i = 1; i <= v; i++) {
    if (!visited[i]) {
      dfs(i, -1);
    }
  }

  cout << articulation_points.size() << nl;
  for (auto x : articulation_points) {
    cout << x << " ";
  }

  return 0;
}


