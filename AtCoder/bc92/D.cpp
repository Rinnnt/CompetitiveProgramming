#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

bool board[100][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b;
  cin >> a >> b;
  bool swap = false;
  if (a > b)
    swap = true;

  int mn = min(a, b);
  int mx = max(a, b);

  int i = 0;
  int j = 0;
  while (mn > 1) {
    for (int di = 0; di < 3; di++)
      for (int dj = 0; dj < 3; dj++)
        if (di != 1 || dj != 1)
          board[i + di][j + dj] = true;
    j += 4;
    if (j == 100) {
      i += 4;
      j = 0;
    }
    mx--;
    mn--;
  }

  i = 99;
  j = 0;
  while (mx) {
    board[i][j] = true;
    j += 2;
    if (j == 100) {
      i -= 2;
      j = 0;
    }
    mx--;
  }

  cout << 100 << " " << 100 << nl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (swap) cout << (board[i][j] ? '.' : '#');
      else cout << (board[i][j] ? '#' : '.');
    }
    cout << nl;
  }

  return 0;
}

