#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[31][5];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  dp[0][0] = 1;
  dp[1][0] = 0;
  dp[1][1] = 0;
  dp[1][2] = 0;
  dp[1][3] = 1;
  dp[1][4] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][1] = dp[i - 1][4];
    dp[i][2] = dp[i - 1][3];
    dp[i][3] = dp[i - 1][0] + dp[i - 1][2];
    dp[i][4] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][0] = dp[i][1] + dp[i][2] + dp[i - 2][0];
  }

  cout << dp[n][0];

  return 0;
}
