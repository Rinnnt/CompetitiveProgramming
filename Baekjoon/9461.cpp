#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;

  for (int i = 6; i <= 100; i++) {
    dp[i] = dp[i - 1] + dp[i - 5];
  }
  
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << nl;
  }

  return 0;
}
