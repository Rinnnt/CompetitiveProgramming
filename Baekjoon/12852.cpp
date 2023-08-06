#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dp[1000005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    } 
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
  }

  cout << dp[n] << nl;
  while (n > 1) {
    cout << n << " ";
    if (dp[n] == dp[n - 1] + 1) {
      n--;
    } else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
      n /= 2;
    } else {
      n /= 3;
    }
  }
  cout << 1;

  return 0;
}
