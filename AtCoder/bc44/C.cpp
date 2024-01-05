#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n, a;
ll dp[51][51][2501];
int x[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> a;
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 2501; k++) {
        if (dp[i][j][k] == 0) continue;
        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
        dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }

  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += dp[n][i][a * i];
  }
  cout << cnt << nl;

  return 0;
}

