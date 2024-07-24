#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<ll> cs(n);
  for (auto &c : cs) cin >> c;

  ll res = 0;

  // take 1

  vector<vector<ll>> dp(n, vector(2, 0LL));
  dp[0][1] = 1;
  dp[1][0] = 1 + cs[1];
  for (int i = 2; i < n - 1; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + cs[i];
    dp[i][1] = dp[i - 1][0] + 1;
  }
  dp[n - 1][0] = max(dp[n - 2][0], dp[n - 2][1]) + cs[n - 1];

  res = dp[n - 1][0];

  // dont take 1

  dp[0][0] = cs[0];
  dp[1][0] = dp[0][0] + cs[1];
  dp[1][1] = dp[0][0] + 1;
  for (int i = 2; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + cs[i];
    dp[i][1] = dp[i - 1][0] + 1;
  }

  res = max(res, max(dp[n - 1][0], dp[n - 1][1]));

  cout << res << nl;

  return 0;
}
