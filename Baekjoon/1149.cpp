#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(3, 1e9));
  for (int i = 0; i < 3; i++) {
    dp[0][i] = a[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j != k) {
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + a[i][j]);
        }
      }
    }
  }

  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

  return 0;
}
