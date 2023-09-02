#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int r, c;
bool cave[101][101];

bool within(int x, int y) {
  return x > 0 && x <= r && y > 0 && y <= c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c;

  for (int i = 1; i <= r; i++) {
    string row;
    cin >> row;
    for (int j = 1; j <= c; j++) {
      cave[i][j] = (row[j - 1] == '.' ? false : true);
    }
  }

  bool left = true;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    h = r + 1 - h;

    pair<int, int> removed = {-1, -1};
    if (left) {
      for (int i = 1; i <= c; i++) {
        if (cave[h][i]) {
          cave[h][i] = false;
          removed = {h, i};
          break;
        }
      }
    } else {
      for (int i = c; i > 0; i--) {
        if (cave[h][i]) {
          cave[h][i] = false;
          removed = {h, i};
          break;
        }
      }
    }
    left = !left;

    if (removed.first == -1) {
      continue;
    }

    vector<pair<int, int>> dxys = {
      {-1, 0}, {0, 1}, {0, -1}, {1, 0}
    };

    for (int i = 0; i < 4; i++) {
      int x = removed.first + dxys[i].first;
      int y = removed.second + dxys[i].second;
      if (within(x, y) && cave[x][y]) {
        queue<pair<int, int>> q;
        set<pair<int, int>> cluster;
        q.push({x, y});
        cluster.insert({x, y});
        if (q.empty()) {
          continue;
        }

        bool grounded = false;
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          if (x == r) {
            grounded = true;
            break;
          }
          for (auto dxy : dxys) {
            int nx = x + dxy.first;
            int ny = y + dxy.second;
            if (within(nx, ny) && !cluster.count({nx, ny}) && cave[nx][ny]) {
              cluster.insert({nx, ny});
              q.push({nx, ny});
            }
          }
        }

        if (grounded) {
          continue;
        }

        int maxdist = 1e9;
        for (auto xy : cluster) {
          int nx = xy.first + 1;
          int dist = 0;
          while (within(nx, xy.second) && (!cave[nx][xy.second] || cluster.count({nx, xy.second}))) {
            dist++;
            nx += 1;
          }
          maxdist = min(maxdist, dist);
        }

        for (auto xy : cluster) {
          cave[xy.first][xy.second] = false;
        }
        for (auto xy : cluster) {
          cave[xy.first + maxdist][xy.second] = true;
        }
        break;
      }
    }

  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << (cave[i][j] ? "x" : ".");
    }
    cout << nl;
  }

}
