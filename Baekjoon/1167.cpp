#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[100001];
int f;
int fdist = 0;

void dfs(int cur, int parent, int dist) {
  if (dist > fdist) {
    fdist = dist;
    f = cur;
  }
  for (auto x : edges[cur]) {
    if (x.first != parent) {
      dfs(x.first, cur, dist + x.second);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int v;
  cin >> v;
  for (int i = 0; i < v; i++) {
    int s;
    cin >> s;
    edges[s].clear();
    int e;
    cin >> e;
    while (e != -1) {
      int dist;
      cin >> dist;
      edges[s].push_back({e, dist});
      cin >> e;
    }
  }

  dfs(1, -1, 0);
  dfs(f, -1, 0);

  cout << fdist;

  return 0;
}
