#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int p[11];
int c[11];
int dp[11][110000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll d, g;
  cin >> d >> g;

  g /= 100;

  for (int i = 1; i <= d; i++) {
    cin >> p[i] >> c[i];
    c[i] /= 100;
  }

  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 110000; j++) {
      dp[i][j] = 1001;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= d; i++) {
    for (int j = 0; j <= p[i]; j++) {
      int score = j * i + (j == p[i] ? c[i] : 0);
      for (int k = 0; k < 110000 - score; k++) {
        dp[i][k + score] = min(dp[i][k + score], dp[i - 1][k] + j);
      }
    }
  }

  int problems = 1001;
  for (int i = g; i < 110000; i++) {
    problems = min(problems, dp[d][i]);
  }

  cout << problems << nl;

  return 0;
}

