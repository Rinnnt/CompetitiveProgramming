#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int m;
      cin >> m;
      int x;
      cin >> x;

      vector<pii> chs(m + 1);
      for (int i = 1; i <= m; i++) {
        cin >> chs[i].first >> chs[i].second;
      }

      vector<vector<ll>> dp(m + 1, vector<ll>(m * x + 1, -1));
      dp[0][0] = 0;

      for (int i = 0; i < m; i++) {
        for (int j = 0; j <= m * x; j++) {
          if (dp[i][j] != -1) {
            if (j >= chs[i + 1].first)
              dp[i + 1][j - chs[i + 1].first + x] = max(dp[i + 1][j - chs[i + 1].first + x], dp[i][j] + chs[i + 1].second);
            dp[i + 1][j + x] = max(dp[i + 1][j + x], dp[i][j]);
          }
        }
      }

      ll ans = 0;
      for (int j = 0; j <= m * x; j++)
        if (dp[m][j] != -1)
          ans = max(ans, dp[m][j]);
      cout << ans << nl;
    }

    return 0;
}
