#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

bool b[401][401];
int p[401][401] = {};

int sum(int tli, int tlj, int bri, int brj) {
  return p[bri][brj] - p[tli - 1][brj] - p[bri][tlj - 1] + p[tli - 1][tlj - 1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int r, c;
  cin >> r >> c;

  for (int i = 1; i <= r; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= c; j++) {
      b[i][j] = s[j - 1] == 'X';
      p[i][j] = b[i][j] + p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
    }
  }

  int ans = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (b[i][j]) continue;


      for (int k = i; k <= r; k++) {
        if (sum(i, j, k, j) > 0) break;

        int l = j;
        int r = c + 1;

        while (l + 1 < r) {
          int mid = (l + r) / 2;

          if (sum(i, j, k, mid) == 0)
            l = mid;
          else
            r = mid;
        }

        ans = max(ans, 2 * ((k - i + 1) + (l - j + 1)));
      }
    }
  }

  cout << ans - 1 << nl;

  return 0;
}

