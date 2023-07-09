#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[1001];
bool visited[1001];

void dfs(int cur) {
  visited[cur] = true;
  for (auto x : edges[cur]) {
    if (!visited[x]) {
      dfs(x);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i <= N; i++) {
    edges[i].clear();
    visited[i] = false;
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int components = 0;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      components++;
      dfs(i);
    }
  }

  cout << components;
}
