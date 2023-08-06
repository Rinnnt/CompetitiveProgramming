#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll n;
ll a[101][101];
ll dp[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 0) {
        if (i + a[i][j] < n) {
          dp[i + a[i][j]][j] += dp[i][j];
        }
        if (j + a[i][j] < n) {
          dp[i][j + a[i][j]] += dp[i][j];
        }
      }
    }
  }
  
  cout << dp[n - 1][n - 1];

  return 0;
}
