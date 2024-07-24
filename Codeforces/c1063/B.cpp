#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, m, r, c, x, y;
string board[2000];
bool visited[2000][2000] = {};
int ans = 1;

bool in_bounds(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r >> c >> x >> y;
    r--; c--;

    for (int i = 0; i < n; i++) {
      cin >> board[i];
    }

    deque<pair<pii, pii>> q;
    q.push_back({{r, c}, {x, y}});
    visited[r][c] = true;
    while (!q.empty()) {
      int i = q.front().first.first;
      int j = q.front().first.second;
      int cx = q.front().second.first;
      int cy = q.front().second.second;
      q.pop_front();
      if (in_bounds(i + 1, j) && board[i + 1][j] != '*' && !visited[i + 1][j]) {
        q.push_front({{i + 1, j}, {cx, cy}});
        visited[i + 1][j] = true;
        ans++;
      }
      if (in_bounds(i - 1, j) && board[i - 1][j] != '*' && !visited[i - 1][j]) {
        q.push_front({{i - 1, j}, {cx, cy}});
        visited[i - 1][j] = true;
        ans++;
      }
      if (in_bounds(i, j + 1) && board[i][j + 1] != '*' && !visited[i][j + 1] && cy > 0) {
        q.push_back({{i, j + 1}, {cx, cy - 1}});
        visited[i][j + 1] = true;
        ans++;
      }
      if (in_bounds(i, j - 1) && board[i][j - 1] != '*' && !visited[i][j - 1] && cx > 0) {
        q.push_back({{i, j - 1}, {cx - 1, cy}});
        visited[i][j - 1] = true;
        ans++;
      }
    }

    cout << ans << nl;

    return 0;
}
