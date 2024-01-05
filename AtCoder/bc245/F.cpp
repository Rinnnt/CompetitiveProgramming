#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> edges[200001];
bool used[200001];
int endless[200001];

void dfs(int v) {
  used[v] = true;

  for (auto x : edges[v]) {
    if (!used[x])
      dfs(x);
    if (endless[x] != -1) endless[v] = 1;
  }
  if (endless[v] != 1) endless[v] = -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    if (!used[i])
      dfs(i);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (endless[i] == 1)
      cnt++;

  cout << cnt << nl;

  return 0;
}

