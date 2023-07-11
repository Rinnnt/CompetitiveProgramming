#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> m >> n;
  vector<vector<int>> board(n, vector<int>(m, 0));
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<pair<int, int>> starts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        starts.push_back({i, j});
        dist[i][j] = 0;
      }
    }
  }

  int maxdays = 0;
  vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  deque<pair<int, int>> q;
  for (auto start : starts) {
    q.push_back(start);
  }
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop_front();
    for (auto d : dxy) {
      int x = cur.first + d.first;
      int y = cur.second + d.second;
      if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != -1 && dist[x][y] > dist[cur.first][cur.second] + 1) {
        dist[x][y] = dist[cur.first][cur.second] + 1;
        maxdays = max(maxdays, dist[x][y]);
        q.push_back({x, y});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] != -1) {
        if (dist[i][j] == 1e9) {
          maxdays = -1;
          break;
        }
      }
    }
  }

  cout << maxdays;

  return 0;
}
