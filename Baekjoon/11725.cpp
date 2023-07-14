#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[100001];
int p[100001];

void dfs(int cur) {
  for (auto x : edges[cur]) {
    if (!p[x]) {
      p[x] = cur;
      dfs(x);
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
    p[i] = 0;
  }
  p[1] = -1;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(1);

  for (int i = 2; i <= n; i++) {
    cout << p[i] << nl;
  }

  return 0;
}
