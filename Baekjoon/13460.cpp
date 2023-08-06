#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  pair<int, int> red, blue;
  vector<string> board;
  vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < x.size(); j++) {
      if (x[j] == 'R') {
        red = {i, j};
        x[j] = '.';
      }
      if (x[j] == 'B') {
        blue = {i, j};
        x[j] = '.';
      }
    }
    board.push_back(x);
  }

  deque<tuple<int, int, int, int, int>> q;
  q.push_back(make_tuple(red.first, red.second, blue.first, blue.second, 0));
  int rx, ry, bx, by, crx, cry, cbx, cby, k, dx, dy, ans = -1;
  while (!q.empty()) {
    rx = get<0>(q.front());
    ry = get<1>(q.front());
    bx = get<2>(q.front());
    by = get<3>(q.front());
    k = get<4>(q.front());
    board[rx][ry] = 'R';
    board[bx][by] = 'B';
    q.pop_front();
    if (k < 10) {
      for (int i = 0; i < 4; i++) {
        bool rf = false;
        bool bf = false;
        board[rx][ry] = 'R';
        board[bx][by] = 'B';
        crx = rx;
        cry = ry;
        cbx = bx;
        cby = by;
        dx = dxy[i].first;
        dy = dxy[i].second;
        while (board[crx + dx][cry + dy] == '.') {
          board[crx][cry] = '.';
          crx += dx;
          cry += dy;
          board[crx][cry] = 'R';
        }
        if (board[crx + dx][cry + dy] == 'O') {
          board[crx][cry] = '.';
          rf = true;
        }
        while (board[cbx + dx][cby + dy] == '.') {
          board[cbx][cby] = '.';
          cbx += dx;
          cby += dy;
          board[cbx][cby] = 'B';
        }
        if (board[cbx + dx][cby + dy] == 'O') {
          board[cbx][cby] = '.';
          bf = true;
        }
        // move red again in case the blue was blocking it at first
        while (board[crx + dx][cry + dy] == '.') {
          board[crx][cry] = '.';
          crx += dx;
          cry += dy;
          board[crx][cry] = 'R';
        }
        if (board[crx + dx][cry + dy] == 'O') {
          board[crx][cry] = '.';
          rf = true;
        }
        if (!bf) {
          q.push_back(make_tuple(crx, cry, cbx, cby, k + 1));
          if (rf) {
            ans = k + 1;
            break;
          }
        }
        board[crx][cry] = '.';
        board[cbx][cby] = '.';
      }
      if (ans != -1) {
        break;
      }
    }
  }

  cout << ans;

  return 0;
}
