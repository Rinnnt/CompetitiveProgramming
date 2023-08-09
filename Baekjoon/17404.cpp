#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n;
int a[1001][3];
ll dp[1001][3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  ll res = 1e9;

  for (int c = 0; c < 3; c++) {
    dp[1][0] = 1e9;
    dp[1][1] = 1e9;
    dp[1][2] = 1e9;
    dp[1][c] = a[1][c];
    for (int i = 2; i <= n; i++) {
      dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = a[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int i = 0; i < 3; i++) {
      if (i != c) {
        res = min(res, dp[n][i]);
      }
    }
  }

  cout << res;

  return 0;
}
