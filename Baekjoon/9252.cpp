#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int dp[1001][1001];
tuple<int, int, int> last[1001][1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string a, b;
  cin >> a >> b;
  for (int i = 0; i <= a.size(); i++) {
    dp[i][0] = 0;
    last[i][0] = make_tuple(-1, -1, -1);
  }
  for (int i = 0; i <= b.size(); i++) {
    dp[0][i] = 0;
    last[0][i] = make_tuple(-1, -1, -1);
  }

  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        last[i][j] = make_tuple(i - 1, j - 1, a[i - 1]);
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          last[i][j] = last[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
          last[i][j] = last[i][j - 1];
        }
      }
    }
  }
  
  char ans[1005];
  int idx = 1000;
  cout << dp[a.size()][b.size()] << nl;
  int i = a.size();
  int j = b.size();
  while (i != -1) {
    ans[idx--] = (char)get<2>(last[i][j]);
    int ni = get<0>(last[i][j]);
    int nj = get<1>(last[i][j]);
    i = ni;
    j = nj;
  }

  for (int i = idx + 2; i < 1001; i++) {
    cout << ans[i];
  }

  return 0;
}
