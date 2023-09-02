#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

ll dp[10001];

ll mod = 987654321;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  dp[0] = 1;
  dp[2] = 1;
  for (int i = 4; i <= n; i += 2) {
    for (int j = 0; j <= i - 2; j += 2) {
      dp[i] = (dp[i] + (dp[j] * dp[i - 2 - j])) % mod;
    }
  }

  cout << dp[n];

  return 0;
}
