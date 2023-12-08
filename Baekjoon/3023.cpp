#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

char b[100][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> b[i][j];
      b[i][2 * c - j - 1] = b[i][j];
      b[2 * r - i - 1][j] = b[i][j];
      b[2 * r - i - 1][2 * c - j - 1] = b[i][j];
    }
  }

  int er, ec;
  cin >> er >> ec;
  er--; ec--;
  b[er][ec] = (b[er][ec] == '.' ? '#' : '.');

  for (int i = 0; i < 2 * r; i++) {
    for (int j = 0; j < 2 * c; j++) {
      cout << b[i][j];
    }
    cout << nl;
  }

  return 0;
}
