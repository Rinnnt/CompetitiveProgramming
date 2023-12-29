#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

char b[501][501];
int dist[501][501];
int visited[501][501];

vector<pair<int, int>> dxys = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      b[i][j] = s[j];
      dist[i][j] = 1e9;
      visited[i][j] = false;
    }
  }

  deque<pii> q;
  q.push_back({0, 0});
  dist[0][0] = 0;

  while (!q.empty()) {
    pii c = q.front();
    q.pop_front();
    int x = c.first;
    int y = c.second;

    if (visited[x][y]) continue;

    visited[x][y] = 1;

    for (auto dxy : dxys) {
      int nx = x + dxy.first;
      int ny = y + dxy.second;

      if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
        if (b[nx][ny] == '.') {
          if (dist[nx][ny] > dist[x][y]) {
            dist[nx][ny] = dist[x][y];
            q.push_front({nx, ny});
          }
        } else {
          for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
              if (nx + i >= 0 && nx + i < h && ny + j >= 0 && ny + j < w) {
                if (dist[nx + i][ny + j] > dist[x][y] + 1) {
                  dist[nx + i][ny + j] = dist[x][y] + 1;
                  q.push_back({nx + i, ny + j});
                }
              }
            }
          }
        }
      }
    }
  }

  cout << dist[h - 1][w - 1] << nl;

  return 0;
}

