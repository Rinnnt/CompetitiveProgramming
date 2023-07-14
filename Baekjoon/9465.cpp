#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int s[100001][2];
int dp[100001][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n; 
    cin >> n;

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> s[j][i];
        dp[j][i] = 0;
      }
    }
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = s[1][0];
    dp[1][1] = s[1][1];

    for (int i = 2; i <= n; i++) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + s[i][0];
      dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + s[i][1];
    }

    cout << max(dp[n][0], dp[n][1]) << nl;
  }

  return 0;
}
