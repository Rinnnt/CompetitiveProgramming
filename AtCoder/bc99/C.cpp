#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int dp[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  dp[0] = 0;
  for (int i = 1; i < 100001; i++) {
    dp[i] = 1e9;
  }

  for (int k = 1; k <= n; k++) {
    dp[k] = min(dp[k - 1] + 1, dp[k]);
    for (int j = 6; k - j >= 0; j *= 6)
      dp[k] = min(dp[k - j] + 1, dp[k]);
    for (int j = 9; k - j >= 0; j *= 9)
      dp[k] = min(dp[k - j] + 1, dp[k]);
  }

  cout << dp[n] << nl;

  return 0;
}

