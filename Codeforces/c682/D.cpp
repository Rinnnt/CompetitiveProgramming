#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int lcs[1001][1001][11][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;

  for (int p = 1; p <= k; p++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        lcs[i + 1][j + 1][p][0] = max(
            max(lcs[i][j + 1][p][0], lcs[i][j + 1][p][1]),
            max(lcs[i + 1][j][p][0], lcs[i + 1][j][p][1])
            );
        if (a[i] == b[j]) {
          lcs[i + 1][j + 1][p][1] = 1 + max(
              lcs[i][j][p][1],
              max(lcs[i][j][p - 1][0], lcs[i][j][p - 1][1])
              );
        }
      }
    }
  }

  cout << max(lcs[n][m][k][0], lcs[n][m][k][1]) << nl;

  return 0;
}
