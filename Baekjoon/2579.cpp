#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[301];
int dp[301][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = a[i] + max(dp[i - 2][0], dp[i - 2][1]);
    dp[i][1] = a[i] + dp[i - 1][0];
  }

  cout << max(dp[n][0], dp[n][1]);

  return 0;
}
