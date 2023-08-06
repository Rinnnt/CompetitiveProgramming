#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n;
int ans = 2;
int board[21][21];

void shifth(int m) {
  int js = m ? n - 2 : 1;
  int d = m ? -1 : 1;
  for (int i = 0; i < n; i++) {
    int merged = -1;
    for (int j = js; j < n && j >= 0; j += d) {
      if (board[i][j] != 0) {
        int p = j - d;
        while (p > 0 && p < n - 1 && board[i][p] == 0) {
          p -= d;
        }
        if (board[i][p] == 0) {
          int temp = board[i][j];
          board[i][j] = 0;
          board[i][p] = temp;
        }
        if (board[i][j] == board[i][p] && p != merged) {
          board[i][p] *= 2;
          board[i][j] = 0;
           ans = max(ans, board[i][p]);
          merged = p;
        } else {
          int temp = board[i][j];
          board[i][j] = 0;
          board[i][p + d] = temp;
        }
      }
    }
  }
}

void shiftv(int m) {
  int is = m ? n - 2 : 1;
  int d = m ? -1 : 1;
  for (int j = 0; j < n; j++) {
    int merged = -1;
    for (int i = is; i < n && i >= 0; i += d) {
      if (board[i][j] != 0) {
        int p = i - d;
        while (p > 0 && p < n - 1 && board[p][j] == 0) {
          p -= d;
        }
        if (board[p][j] == 0) {
          int temp = board[i][j];
          board[i][j] = 0;
          board[p][j] = temp;
        }
        if (board[i][j] == board[p][j] && p != merged) {
          board[p][j] *= 2;
          board[i][j] = 0;
          ans = max(ans, board[p][j]);
          merged = p;
        } else {
          int temp = board[i][j];
          board[i][j] = 0;
          board[p + d][j] = temp;
        }
      }
    }
  }
}

void shift(int m) {
  if (m == 0) {
    shifth(0);
  } else if (m == 1) {
    shifth(1);
  } else if (m == 2) {
    shiftv(0);
  } else {
    shiftv(1);
  }
}

void solve(int steps) {
  if (steps == 0) {
    return;
  } else {
    vector<int> orig;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        orig.push_back(board[i][j]);
      }
    }
    for (int m = 0; m < 4; m++) {
      shift(m);
      solve(steps - 1);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          board[i][j] = orig[i * n + j];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      ans = max(ans, board[i][j]);
    }
  }

  solve(5);

  cout << ans;

  return 0;
}
