#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int a[101];
int odds[101];
int dp[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    odds[i] += a[i] % 2 + odds[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][n] = 0;
  }

  for (int k = n - 1; k > 0; k--) {
    for (int l = 1; l <= n; l++) {
      int r = (l + k - 1) % n;
      if (!r) r = n;
      int todds = (l <= r ? odds[n] - odds[r] + odds[l - 1] : odds[l - 1] - odds[r]);
      int prev = l - 1;
      if (!prev) prev = n;
      dp[l][k] = max(
          todds - dp[l][k + 1],
          todds - dp[prev][k + 1]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (2 * (odds[n] - dp[i][1]) > odds[n])
      ans++;

  cout << ans << nl;

  return 0;
}

