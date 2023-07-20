#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int mod = 1e9;
int dp[2][10][1024];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 1024; j++) {
      dp[1][i][j] = 0;
    }
  }
  for (int i = 1; i < 10; i++) {
    dp[1][i][1 << i] = 1;
  }

  for (int k = 2; k <= n; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 1024; j++) {
        dp[k % 2][i][j] = 0;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (i == 0) {
        for (int j = 0; j < 1024; j++) {
          dp[k % 2][i][j | (1 << i)] += dp[1 - (k % 2)][i + 1][j];
          dp[k % 2][i][j | (1 << i)] %= mod;
        }
      } else if (i == 9) {
        for (int j = 0; j < 1024; j++) {
          dp[k % 2][i][j | (1 << i)] += dp[1 - (k % 2)][i - 1][j];
          dp[k % 2][i][j | (1 << i)] %= mod;
        }
      } else {
        for (int j = 0; j < 1024; j++) {
          dp[k % 2][i][j | (1 << i)] += dp[1 - (k % 2)][i - 1][j];
          dp[k % 2][i][j | (1 << i)] %= mod;
          dp[k % 2][i][j | (1 << i)] += dp[1 - (k % 2)][i + 1][j];
          dp[k % 2][i][j | (1 << i)] %= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans = (ans + dp[n % 2][i][1023]) % mod;
  }

  cout << ans;

  return 0;
}
