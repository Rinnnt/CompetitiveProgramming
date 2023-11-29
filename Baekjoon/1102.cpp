#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

int p[16][16];
int dp[70000];

int calculate(int n) {
  if (dp[n] != -1)
    return dp[n];

  int res = 1e9;
  for (int i = 0; i < 16; i++) {
    if ((n >> i) & 1) {
      int m = n - (1 << i);
      int mc = 1e9;
      for (int j = 0; j < 16; j++)
        if ((n >> j) & 1 && j != i)
          mc = min(mc, p[j][i]);
      res = min(res, calculate(m) + mc);
    }
  }

  return dp[n] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> p[i][j];

  for (int i = 0; i < 70000; i++)
    dp[i] = -1;

  string s;
  cin >> s;
  int cur = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    cur <<= 1;
    if (s[i] == 'Y')
      cur++;
  }
  dp[cur] = 0;

  int r;
  cin >> r;

  if (r <= __builtin_popcount(cur)) {
    cout << 0 << nl;
    return 0;
  }

  int ans = 1e9;
  for (int i = 0; i < (1 << n); i++)
    if (__builtin_popcount(i) == r)
      ans = min(ans, calculate(i));

  if (ans == 1e9)
    cout << -1 << nl;
  else
    cout << ans << nl;

  return 0;
}
