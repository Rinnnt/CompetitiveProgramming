#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n;
int m[101][101];
int dist[101][101];

bool within(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }

  vector<pair<int, int>> dxys = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
  };

  int color = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == 1) {
        color++;
        queue<pair<int, int>> q;
        q.push({i, j});
        m[i][j] = color;

        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();

          for (auto dxy : dxys) {
            int nx = x + dxy.first;
            int ny = y + dxy.second;
            if (within(nx, ny) && m[nx][ny] == 1) {
              m[nx][ny] = color;
              q.push({nx, ny});
            }
          }
        }
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == 0) {
        continue;
      }

      bool water = false;
      for (auto dxy : dxys) {
        int nx = i + dxy.first;
        int ny = j + dxy.second;
        if (within(nx, ny) && m[nx][ny] == 0) {
          water = true;
        }
      }

      if (!water) {
        continue;
      }

      for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
          dist[ii][jj] = -1;
        }
      }

      queue<pair<int, int>> q;
      q.push({i, j});
      dist[i][j] = 0;
      while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (m[x][y] != 0 && m[x][y] != m[i][j]) {
          ans = min(ans, dist[x][y] - 1);
          break;
        }

        for (auto dxy : dxys) {
          int nx = x + dxy.first;
          int ny = y + dxy.second;
          if (within(nx, ny) && m[nx][ny] != m[i][j] && dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
          }
        }
      }
    }
  }

  cout << ans;

  return 0;
}
