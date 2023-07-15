#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[501][501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = 1e12;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      for (int k = 1; k < i; k++) {
        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][j + k - 1] + dp[j + k][j + i - 1] + a[j].first * a[j + k - 1].second * a[j + i - 1].second);
        //cout << "DP of " << j << " " << j + i - 1 << " : " << dp[j][j + i - 1] << " ( " << dp[j][j + k - 1] << " "  << dp[j + k][j + i - 1] << nl;
      }
    }
  }

  cout << dp[0][n - 1];

  return 0;
}
