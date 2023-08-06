#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n;
int dist[17][17];
int dp[17][200000];

int solve(int cur, int visited) {
  if (visited == (1 << n) - 1) {
    return dist[cur][0] ? dist[cur][0] : 1e9;
  }
  if (dp[cur][visited] != -1) {
    return dp[cur][visited];
  }
  dp[cur][visited] = 1e9;
  for (int i = 1; i < n; i++) {
    if (dist[cur][i] == 0) {
      continue;
    }
    if ((visited & (1 << i)) == (1 << i)) {
      continue;
    }
    dp[cur][visited] = min(dp[cur][visited], dist[cur][i] + solve(i, visited | (1 << i)));
  }
  return dp[cur][visited];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(0, 1);

  return 0;
}
