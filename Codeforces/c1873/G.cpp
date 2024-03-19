#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      string s;
      cin >> s;

      int n = s.size();

      vector<int> ls(n);
      vector<int> rs(n);
      int as = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'A') as++;
        else {
          ls[i] = as;
          as = 0;
        }
      }
      as = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') as++;
        else {
          rs[i] = as;
          as = 0;
        }
      }

      vector<vector<int>> dp(n + 5, vector<int>(2, 0));
      int idx = 2;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
          dp[idx][0] = max(dp[idx - 2][1] + ls[i], dp[idx - 1][0] + ls[i]);
          dp[idx][1] = max(dp[idx - 1][0] + rs[i], dp[idx - 1][1] + rs[i]);
          idx++;
        }
      }

      cout << max(dp[idx - 1][0], dp[idx - 1][1]) << nl;
    }

    return 0;
}
