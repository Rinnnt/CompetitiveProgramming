#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t; 
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      p[i] = p[i - 1] + a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      dp[i][i] = a[i];
    }
    for (int k = 2; k <= n; k++) {
      for (int i = 1; i <= n - k + 1; i++) {
        int tot = p[i + k - 1] - p[i - 1];
        dp[i][i + k - 1] = max(tot - dp[i][i + k - 2], tot - dp[i + 1][i + k - 1]);
      }
    }

    cout << dp[1][n] << nl;
  }

  return 0;
}
