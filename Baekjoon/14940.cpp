#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  pair<int, int> start;
  vector<vector<int>> board(n, vector<int>(m, 0));
  vector<vector<int>> dist(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        start = {i, j};
      }
      if (board[i][j] == 0) {
        dist[i][j] = 0;
      }
    }
  }

  vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  set<pair<int, int>> visited;
  deque<pair<int, int>> q;
  q.push_back(start);
  visited.insert(start);
  dist[start.first][start.second] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop_front();
    for (int i = 0; i < dxy.size(); i++) {
      int x = cur.first + dxy[i].first;
      int y = cur.second + dxy[i].second;
      if (x >= 0 && x < n && y >= 0 && y < m && !visited.count({x, y})) {
        visited.insert({x, y});
        if (!board[x][y] == 0) {
          dist[x][y] = dist[cur.first][cur.second] + 1;
          q.push_back({x, y});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dist[i][j] << " ";
    }
    cout << nl;
  }

  return 0;
}
