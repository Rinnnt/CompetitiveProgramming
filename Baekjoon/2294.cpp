#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, k;
int coins[101];
ll dp[10001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    dp[i] = 1e9;
  }
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  dp[0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - coins[j] >= 0) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  cout << (dp[k] == 1e9 ? -1 : dp[k]);

  return 0;
}
