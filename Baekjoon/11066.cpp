#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int p[501];
int dp[501][501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    p[0] = 0;
    for (int i = 1; i <= k; i++) {
      cin >> p[i];
      p[i] += p[i - 1];
      dp[i][i] = 0;
    }

    for (int i = 1; i < k; i++) {
      dp[i][i + 1] = p[i + 1] - p[i - 1];
    }

    for (int i = 2; i < k; i++) {
      for (int j = 1; j <= k - i; j++) {
        dp[j][j + i] = 1e9;
        for (int l = 0; l < i; l++) {
          dp[j][j + i] = min(dp[j][j + i], dp[j][j + l] + dp[j + l + 1][j + i] + p[j + l] - p[j - 1] + p[j + i] - p[j + l]);
        }
      }
    }

    cout << dp[1][k] << nl;

  }

  return 0;
}
