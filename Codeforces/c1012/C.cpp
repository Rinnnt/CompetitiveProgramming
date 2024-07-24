#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int as[5002];
int dp[5001][2501][2];
int ans[5002];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= (n + 1) / 2; j++)
      for (int k = 0; k < 2; k++)
        dp[i][j][k] = 1e9;

  for (int j = 1; j <= (n + 1) / 2; j++)
    ans[j] = 1e9;

  for (int i = 1; i <= n; i++) cin >> as[i];

  dp[1][1][1] = max(as[2] - as[1] + 1, 0);
  dp[2][1][0] = max(as[2] - as[1] + 1, 0);
  dp[2][1][1] = max(as[1] - as[2] + 1, 0) + max(as[3] - as[2] + 1, 0);
  ans[1] = min(dp[2][1][1], dp[1][1][1]);

  for (int i = 1; i <= n; i++)
    dp[i][0][0] = 0;

  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= (i + 1) / 2; j++) {
      dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);

      if (as[i - 2] > as[i - 1]) {
        dp[i][j][1] = dp[i - 2][j - 1][1] + max(as[i - 1] - as[i] + 1, 0);
      } else {
        dp[i][j][1] = dp[i - 2][j - 1][1] + max((as[i - 2] - 1) - as[i] + 1, 0);
      }
      dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][0] + max(as[i - 1] - as[i] + 1, 0));

      dp[i][j][1] += max(as[i + 1] - as[i] + 1, 0);
      ans[j] = min(ans[j], min(dp[i][j][0], dp[i][j][1]));
    }
  }

  for (int j = 1; j <= (n + 1) / 2; j++)
    cout << ans[j] << " ";
  cout << nl;

  return 0;
}
