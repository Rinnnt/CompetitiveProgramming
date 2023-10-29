#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[100005];
int tin[100005] = {};
int low[100005] = {};
bool visited[100005];
int timer = 0;
vector<pair<int, int>> bridges;

void dfs(int cur, int parent) {
  visited[cur] = true;
  tin[cur] = ++timer;
  low[cur] = tin[cur];

  for (auto x : edges[cur]) {
    if (!visited[x]) {
      dfs(x, cur);
      low[cur] = min(low[cur], low[x]);
      if (low[x] > tin[cur]) {
        bridges.push_back({min(cur, x), max(cur, x)});
      }
    } else if (visited[x] && x != parent) {
      low[cur] = min(low[cur], tin[x]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int v, e;
  cin >> v >> e;

  bridges.clear();
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

  sort(bridges.begin(), bridges.end());
  cout << bridges.size() << nl;
  for (auto bridge : bridges) {
    cout << bridge.first << " " << bridge.second << nl;
  }

  return 0;
}


