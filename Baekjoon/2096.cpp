#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dp[2][6];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;
  dp[0][4] = 0;
  dp[0][5] = 0;
  
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[i % 2][0] = max(dp[1 - (i % 2)][0], dp[1 - (i % 2)][1]) + a;
    dp[i % 2][1] = max(max(dp[1 - (i % 2)][0], dp[1 - (i % 2)][1]), dp[1 - (i % 2)][2]) + b;
    dp[i % 2][2] = max(dp[1 - (i % 2)][1], dp[1 - (i % 2)][2]) + c;
    dp[i % 2][3] = min(dp[1 - (i % 2)][3], dp[1 - (i % 2)][4]) + a;
    dp[i % 2][4] = min(min(dp[1 - (i % 2)][3], dp[1 - (i % 2)][4]), dp[1 - (i % 2)][5]) + b;
    dp[i % 2][5] = min(dp[1 - (i % 2)][4], dp[1 - (i % 2)][5]) + c;
  }
  cout << max(max(dp[n % 2][0], dp[n % 2][1]), dp[n % 2][2]) << " " << min(min(dp[n % 2][3], dp[n % 2][4]), dp[n % 2][5]);

  return 0;
}
