#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int f;
int fdist;

vector<pair<int, int>> edges[10001];
int dist[10001];

void dfs(int cur, int parent) {
  for (auto x : edges[cur]) {
    if (x.first != parent) {
      dist[x.first] = dist[cur] + x.second;
      if (dist[x.first] > fdist) {
        fdist = dist[x.first];
        f = x.first;
      }
      dfs(x.first, cur);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    edges[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e, t;
    cin >> s >> e >> t;
    edges[s].push_back({e, t});
    edges[e].push_back({s, t});
  }

  dist[1] = 0;
  dfs(1, -1);
  dist[f] = 0;
  dfs(f, -1);

  cout << fdist;

  return 0;
}
