#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> edges[1000001];
int dp[1000001][2];

void find(int cur, int parent) {
  dp[cur][1] = 1;
  for (auto x : edges[cur]) {
    if (x != parent) {
      find(x, cur);
      dp[cur][0] += dp[x][1];
      dp[cur][1] += min(dp[x][0], dp[x][1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  find(1, -1);

  cout << min(dp[1][0], dp[1][1]);

  return 0;
}
