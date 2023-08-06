#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int mod = 1000000;
int dp[5001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  bool c = true;
  dp[0] = 1;
  if (s[0] == '0') {
    c = false;
  } else {
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
      if (s[i - 1] == '0') {
        if (s[i - 2] != '1' && s[i - 2] != '2') {
          c = false;
          break;
        }
        dp[i] = dp[i - 2];
      } else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
      } else {
        dp[i] = dp[i - 1];
      }
    }
  }

  cout << (c ? dp[s.size()] : 0);

  return 0;
}
