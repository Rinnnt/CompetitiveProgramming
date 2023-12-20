#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

ll dp[1002][1024][10] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 1; i <= n; i++) {
    int idx = (s[i - 1] - 'A');
    int mask = 1 << idx;
    for (int j = 0; j < 1024; j++) {
      for (int k = 0; k < 10; k++) {
        dp[i][j][k] = (dp[i - 1][j][k] + (idx == k ? dp[i - 1][j][k] : 0)) % mod;
      }
    }

    for (int j = 0; j < 1024; j++) {
      for (int k = 0; k < 10; k++) {
        if (j != (j | mask)) {
          dp[i][j | mask][idx] = (dp[i][j | mask][idx] + dp[i - 1][j][k]) % mod;
        }
      }
    }

    dp[i][mask][idx] = (dp[i][mask][idx] + 1) % mod;
  }

  ll ans = 0;
  for (int i = 0; i < 1024; i++) {
    for (int j = 0; j < 10; j++) {
      ans = (ans + dp[n][i][j]) % mod;
    }
  }
  cout << ans << nl;

  return 0;
}

