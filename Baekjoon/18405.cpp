#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n, k;

int board[2][201][201];

bool within(int x, int y) {
  return x > 0 && x <= n && y > 0 && y <= n;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[0][i][j];
      if (board[0][i][j] == 0) {
        board[0][i][j] = 1e9;
      }
      board[1][i][j] = 1e9;
    }
  }

  vector<pair<int, int>> dxys = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
  };

  int s, x, y;
  cin >> s >> x >> y;
  s = min(s, 400);
  for (int k = 0; k < s; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (board[k & 1][i][j] == 1e9) {
          for (auto dxy : dxys) {
            int ni = i + dxy.first;
            int nj = j + dxy.second;
            if (within(ni, nj)) {
              board[(k & 1) ^ 1][i][j] = min(board[(k & 1) ^ 1][i][j], board[k & 1][ni][nj]);
            }
          }
        } else {
          board[(k & 1) ^ 1][i][j] = board[k & 1][i][j];
        }
      }
    }
  }


  if (board[s & 1][x][y] == 1e9) {
    cout << 0;
  } else {
    cout << board[s & 1][x][y];
  }

  return 0;
}
