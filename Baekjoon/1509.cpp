#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool palin[2501][2501];
int dp[2501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  int slen = s.size();
  for (int i = 0; i < slen; i++) {
    palin[i][i] = true;
  }
  for (int i = 0; i < slen - 1; i++) {
    palin[i][i + 1] = s[i] == s[i + 1];
  }
  for (int k = 2; k < slen; k++) {
    for (int i = 0; i < slen - k; i++) {
      palin[i][i + k] = palin[i + 1][i + k - 1] && s[i] == s[i + k];
    }
  }

  dp[0] = 0;
  for (int i = 1; i <= slen; i++) {
    dp[i] = 1e9;
    for (int j = 0; j < i; j++) {
      if (palin[j][i - 1]) {
        dp[i] = min(dp[i], dp[j] + 1);
      }
    }
  }

  cout << dp[slen];

  return 0;
}
