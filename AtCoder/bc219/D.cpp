#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int xys[2][301][301];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, x, y;
  cin >> n >> x >> y;

  for (int j = 0; j <= x; j++) {
    for (int k = 0; k <= y; k++) {
      xys[0][j][k] = 1e9;
      xys[1][j][k] = 1e9;
    }
  }
  xys[1][0][0] = 0;

  for (int i = 0; i < n; i++) {
    int a, b, idx, oidx;
    cin >> a >> b;
    idx = i % 2;
    oidx = 1 - idx;
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y; k++) {
        int nj = min(j + a, x);
        int nk = min(k + b, y);
        xys[idx][j][k] = min(xys[idx][j][k], xys[oidx][j][k]);
        xys[idx][nj][nk] = min(xys[idx][nj][nk], xys[oidx][j][k] + 1);
      }
    }
  }

  cout << (xys[1 - (n % 2)][x][y] == 1e9 ? -1 : xys[1 - (n % 2)][x][y]) << nl;

  return 0;
}

