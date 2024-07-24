#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  vector<int> dp(n, -1);

  int ans = 0;
  int anscnt = 1;

  deque<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      st.push_back(i);
    else {
      if (st.empty()) continue;

      int l = st.back();
      st.pop_back();
      dp[i] = (i - l + 1);
      if (l > 0 && dp[l - 1] != -1)
        dp[i] += dp[l - 1];

      if (dp[i] > ans) {
        ans = dp[i];
        anscnt = 1;
      } else if (dp[i] == ans) {
        anscnt++;
      }

    }
  }

  cout << ans << " " << anscnt << nl;

  return 0;
}
