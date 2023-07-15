#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int d[1001][1001][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j][0] = d[i][j][1] = 1e9;
    }
  }
  d[0][0][0] = 1;

  vector<pair<int, int>> dxys = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  deque<tuple<int, int, int>> q;
  q.push_back(make_tuple(0, 0, 0));
  while (!q.empty()) {
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int broken = get<2>(q.front());
    q.pop_front();
    for (auto dxy : dxys) {
      int nx = x + dxy.first;
      int ny = y + dxy.second;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (broken == 1) {
          if (b[nx][ny] != '1' && d[x][y][1] + 1 < d[nx][ny][1]) {
            d[nx][ny][1] = d[x][y][1] + 1;
            q.push_back(make_tuple(nx, ny, 1));
          }
        } else {
          if (b[nx][ny] == '1' && d[x][y][0] + 1 < d[nx][ny][1]) {
            d[nx][ny][1] = d[x][y][0] + 1;
            q.push_back(make_tuple(nx, ny, 1));
          } else if (b[nx][ny] == '0' && d[x][y][0] + 1 < d[nx][ny][0]) {
            d[nx][ny][0] = d[x][y][0] + 1;
            q.push_back(make_tuple(nx, ny, 0));
          }
        }
      }
    }
  }

  if (d[n - 1][m - 1][0] == 1e9 && d[n - 1][m - 1][1] == 1e9) {
    cout << -1;
  } else {
    cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
  }


  return 0;
}
