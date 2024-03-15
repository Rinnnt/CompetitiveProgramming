#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 1e9 + 7;

ll dp[200001][64];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;
      vector<int> as(n);
      for (auto &a : as) cin >> a;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++)
          dp[i + 1][j] = dp[i][j];
        dp[i + 1][as[i]] += 1;
        for (int j = 0; j < 64; j++) {
          dp[i + 1][as[i] & j] += dp[i][j];
          dp[i + 1][as[i] & j] %= mod;
        }
      }

      ll ans = 0;
      for (int j = 0; j < 64; j++)
        if (__builtin_popcount(j) == k)
          ans = (ans + dp[n][j]) % mod;
      cout << ans << nl;
    }

    return 0;
}
