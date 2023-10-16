#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

bool dp[2][1001][1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int c, n;
  cin >> c >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  dp[1][0][0] = true;

  int first = 0;
  int second = 0;
  int best = 0;
  int diff = 0;


  for (int k = 0; k < n; k++) {
    int dpi = k % 2;
    int dpoi = 1 - dpi;
    for (int i = 0; i < c + 1; i++) {
      for (int j = 0; j < c + 1; j++) {
        dp[dpi][i][j] = dp[dpoi][i][j];
        if (i - a[k] >= 0) {
          dp[dpi][i][j] |= dp[dpoi][i - a[k]][j];
        }
        if (j - a[k] >= 0) {
          dp[dpi][i][j] |= dp[dpoi][i][j - a[k]];
        }
        if (dp[dpi][i][j] && (i + j > best || (i + j == best && abs(i - j) < diff))) {
          best = i + j;
          diff = abs(i - j);
          first = max(i, j);
          second = min(i, j);
        }
      }
    }
  }

  cout << first << " " << second;

}
