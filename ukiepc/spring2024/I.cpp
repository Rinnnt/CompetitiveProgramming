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

      vector<vector<ll>> dp(m + 1, vector<ll>(m * 1000 + 1, -1));
      dp[0][0] = 0;

      for (int i = 0; i < m; i++) {
        for (int j = 0; j <= m * 1000; j++) {
          if (dp[i][j] != -1) {
            if (dp[i][j] >= chs[i + 1].first)
              dp[i + 1][j + chs[i + 1].second] = max(dp[i + 1][j + chs[i + 1].second], dp[i][j] - chs[i + 1].first + x);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
          }
        }
      }

      int ans = 0;
      for (int j = 0; j <= m * 1000; j++)
        if (dp[m][j] != -1)
          ans = max(ans, j);
      cout << ans << nl;
    }

    return 0;
}
