#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int dp[101][101][301];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, w;
  cin >> n >> w;
  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  ll a0 = a[0].first;
  for (int i = 0; i < n; i++) {
    a[i].first -= a0;
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 301; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  dp[0][0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 301; k++) {
        if (dp[i][j][k] == -1) continue;
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        dp[i + 1][j + 1][k + a[i].first] = max(dp[i][j][k + a[i].first], dp[i][j][k] + a[i].second);
      }
    }
  }

  int ans = 0;
  for (int j = 0; j <= n; j++) {
    for (int k = 0; k < 301; k++) {
      if (j * a0 + k <= w) {
        ans = max(ans, dp[n][j][k]);
      }
    }
  }

  cout << ans << nl;

  return 0;
}

