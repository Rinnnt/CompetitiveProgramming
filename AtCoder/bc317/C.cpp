#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> edges[11];
bool visited[11];

int solve(int cur) {
  int ans = 0;
  for (auto x : edges[cur]) {
    if (!visited[x.first]) {
      visited[x.first] = true;
      ans = max(ans, solve(x.first) + x.second);
      visited[x.first] = false;
    }
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
      visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      edges[u].push_back({v, c});
      edges[v].push_back({u, c});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      visited[i] = true;
      ans = max(ans, solve(i));
      visited[i] = false;
    }

    cout << ans << nl;

    return 0;
}
