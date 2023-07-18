#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

string board[9];
int possible[9][9][9];

void edit(int i, int j, int c, int add) {
  if (add == 1) {
    board[i][j] = '1' + c;
  } else {
    board[i][j] = '0';
  }
  for (int k = 0; k < 9; k++) {
    possible[k][j][c] += add;
    possible[i][k][c] += add;
  }
  for (int p = 3 * (i / 3); p < 3 * (i / 3) + 3; p++) {
    for (int q = 3 * (j / 3); q < 3 * (j / 3) + 3; q++) {
      possible[p][q][c] += add;
    }
  }
}

bool solve(void) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '0') {
        bool found = false;
        for (int k = 0; k < 9; k++) {
          if (possible[i][j][k] == 0) {
            edit(i, j, k, 1);
            if (solve()) {
              found = true;
              break;
            } 
            edit(i, j, k, -1);
          }
        }
        if (!found) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 9; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        possible[i][j][k] = 0;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '0') {
        edit(i, j, board[i][j] - '1', 1);
      }
    }
  }

  solve();

  for (auto x : board) {
    cout << x << nl;
  }

  return 0;
}
