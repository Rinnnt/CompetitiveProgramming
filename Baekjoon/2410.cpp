#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int mod = 1e9;
int dp[1000001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  dp[0] = 1;
  for (int i = 1; i <= n; i *= 2) {
    for (int j = 0; j <= n - i; j++) {
      dp[j + i] = (dp[j + i] + dp[j]) % mod;
    }
  }

  cout << dp[n];

  return 0;
}
