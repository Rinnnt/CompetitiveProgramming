#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 1e9 + 7;

ll dp[1001][10001] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, c;
  cin >> n >> c;

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int l = 0;
    ll sum = 0;
    for (int r = 0; r <= min(10000, i * (i - 1) / 2); r++) {
      sum += dp[i - 1][r];
      if (r - l + 1 > i)
        sum -= dp[i - 1][l++];
      sum = (sum + mod) % mod;
      dp[i][r] = sum;
    }
  }

  cout << dp[n][c] << nl;

  return 0;
}

