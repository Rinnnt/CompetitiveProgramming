#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, k;
int dp[100001][21];
int cs[100001];

vector<int> edges[100001];

int solve(int cur, int k) {
  if (dp[cur][k] != -1) return dp[cur][k];

  if (k == 0)
    return dp[cur][k] = cs[cur];

  dp[cur][k] = cs[cur];
  for (auto v : edges[cur]) {
    for (int i = 1; i <= k; i++) {
      if (i % 2)
        dp[cur][k] += solve(v, k - i);
      else
        dp[cur][k] -= solve(cur, k - i);
    }
  }

  return dp[cur][k];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 21; j++)
      dp[i][j] = -1;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    cin >> cs[i];

  for (int i = 1; i <= n; i++) {
    cout << solve(i, k) << nl;
  }

  return 0;
}
