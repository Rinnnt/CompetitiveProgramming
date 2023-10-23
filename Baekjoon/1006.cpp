#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF 1e9
#define MOD 1000000

int dp[4][10005][3];
int e[10005][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {

    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
      cin >> e[i][0];
    }
    for (int i = 0; i < n; i++) {
      cin >> e[i][1];
    }
    for (int k = 0; k < 4; k++) {
      for (int i = 0; i < 10005; i++) {
        for (int j = 0; j < 3; j++) {
          dp[k][i][j] = 1e9;
        }
      }
    }

    dp[0][0][0] = 0; // normal dp
    dp[1][0][0] = 0; // dp assume e[0][0] and e[n-1][0] is taken
    dp[2][0][0] = 0; // dp assume e[0][1] and e[n-1][1] is taken
    dp[3][0][0] = 0; // dp assume both taken from dp[1] and dp[2]

    for (int k = 0; k < 4; k++) {
      if ((k == 1 && e[0][0] + e[n - 1][0] > w)
          || (k == 2 && e[0][1] + e[n - 1][1] > w)
          || (k == 3 && (e[0][0] + e[n - 1][0] > w || e[0][1] + e[n - 1][1] > w))) {
        continue;
      }
      if (k == 1) {
        dp[1][1][1] = 0;
      }
      if (k == 2) {
        dp[2][1][2] = 0;
      }
      if (k == 3) {
        dp[3][1][0] = 0;
        dp[3][1][1] = 0;
        dp[3][1][2] = 0;
      }

      for (int i = 1; i <= n; i++) {
        // |o
        // |
        dp[k][i][1] = min(dp[k][i][1], dp[k][i - 1][0] + 1);
        if (i > 1 && e[i - 1][0] + e[i - 2][0] <= w) {
          dp[k][i][1] = min(dp[k][i][1], dp[k][i - 1][2] + 1);
        }

        // |
        // |o
        dp[k][i][2] = min(dp[k][i][2], dp[k][i - 1][0] + 1);
        if (i > 1 && e[i - 1][1] + e[i - 2][1] <= w) {
          dp[k][i][2] = min(dp[k][i][2], dp[k][i - 1][1] + 1);
        }

        // |o
        // |o
        dp[k][i][0] = min(dp[k][i][0], min(dp[k][i][1] + 1, dp[k][i][2] + 1));
        if (e[i - 1][0] + e[i - 1][1] <= w) {
          dp[k][i][0] = min(dp[k][i][0], dp[k][i - 1][0] + 1);
        }
        if (i > 1 && e[i - 1][0] + e[i - 2][0] <= w && e[i - 1][1] + e[i - 2][1] <= w) {
          dp[k][i][0] = min(dp[k][i][0], dp[k][i - 2][0] + 2);
        }
      }
    }

    int ans = dp[0][n][0];
    ans = min(ans, dp[1][n][2] + 1);
    ans = min(ans, dp[2][n][1] + 1);
    ans = min(ans, dp[3][n - 1][0] + 2);

    cout << ans << nl;
  }

  return 0;
}
