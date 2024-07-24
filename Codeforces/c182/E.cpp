#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, l;
  cin >> n >> l;

  vector<vector<vector<int>>> dp(3001, vector(101, vector(2, 0)));

  vector<pii> fs(n);
  for (auto &f : fs) cin >> f.first >> f.second;

  for (int i = 0; i < n; i++) {
    dp[fs[i].first][i][0] = 1;
    if (fs[i].first != fs[i].second)
      dp[fs[i].second][i][1] = 1;
  }

  for (int i = 1; i <= l; i++) {
    for (int j = 0; j < n; j++) {
      int a = fs[j].first;
      int b = fs[j].second;

      if (i >= a) {
        for (int k = 0; k < n; k++) {
          if (j == k) continue;
          if (fs[k].second == a)
            dp[i][j][0] = (dp[i][j][0] + dp[i - a][k][0]) % mod;
          if (fs[k].first != fs[k].second && fs[k].first == a)
            dp[i][j][0] = (dp[i][j][0] + dp[i - a][k][1]) % mod;
        }
      }

      if (a != b && i >= b) {
        for (int k = 0; k < n; k++) {
          if (j == k) continue;
          if (fs[k].second == b)
            dp[i][j][1] = (dp[i][j][1] + dp[i - b][k][0]) % mod;
          if (fs[k].first != fs[k].second && fs[k].first == b)
            dp[i][j][1] = (dp[i][j][1] + dp[i - b][k][1]) % mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      ans = (ans + dp[l][i][j]) % mod;

  cout << ans << nl;

  return 0;
}
