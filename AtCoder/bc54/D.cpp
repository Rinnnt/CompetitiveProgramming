#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int dp[401][401];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, ma, mb;
  cin >> n >> ma >> mb;

  for (int i = 0; i < 401; i++) {
    for (int j = 0; j < 401; j++) {
      dp[i][j] = 1e9;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 400; i >= a; i--) {
      for (int j = 400; j >= b; j--) {
        dp[i][j] = min(dp[i][j], dp[i - a][j - b] + c);
      }
    }
  }

  int mincost = 1e9;
  int ca = ma;
  int cb = mb;
  while (ca < 401 && cb < 401) {
    mincost = min(mincost, dp[ca][cb]);
    ca += ma;
    cb += mb;
  }

  cout << (mincost == 1e9 ? -1 : mincost) << nl;

  return 0;
}

