#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll n, k;
ll mod = 1e9;
ll dp[201][201];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n - j; k++) {
        dp[i][k + j] = (dp[i][k + j] + dp[i - 1][k]) % mod;
      }
    }
  }

  cout << dp[k][n];

  return 0;
}
