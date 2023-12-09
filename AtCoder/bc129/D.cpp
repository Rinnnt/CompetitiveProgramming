#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'
#define pii pair<int, int>

int h, w;
char b[2000][2000];
int f[2000][2000][4];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> h >> w;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> b[i][j];

  for (int i = 0; i < h; i++) {
    f[i][0][0] = 0;
    for (int j = 1; j < w; j++) {
      if (b[i][j - 1] == '#') f[i][j][0] = 0;
      else f[i][j][0] = f[i][j - 1][0] + 1;
    }
  }

  for (int i = 0; i < h; i++) {
    f[i][w - 1][1] = 0;
    for (int j = w - 2; j >= 0; j--) {
      if (b[i][j + 1] == '#') f[i][j][1] = 0;
      else f[i][j][1] = f[i][j + 1][1] + 1;
    }
  }

  for (int j = 0; j < w; j++) {
    f[0][j][2] = 0;
    for (int i = 1; i < h; i++) {
      if (b[i - 1][j] == '#') f[i][j][2] = 0;
      else f[i][j][2] = f[i - 1][j][2] + 1;
    }
  }

  for (int j = 0; j < w; j++) {
    f[h - 1][j][3] = 0;
    for (int i = h - 2; i >= 0; i--) {
      if (b[i + 1][j] == '#') f[i][j][3] = 0;
      else f[i][j][3] = f[i + 1][j][3] + 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (b[i][j] != '#')
        ans = max(ans, 1 + f[i][j][0] + f[i][j][1] + f[i][j][2] + f[i][j][3]);
  cout << ans << nl;

  return 0;
}

