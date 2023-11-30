#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'
#define pii pair<int, int>

int r, c;
char b[50][50];
int f[50][50];
int dist[50][50];

bool in_bound(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

pii dxys[4] = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c;

  pii start;
  pii end;
  queue<pair<pii, int>> q;
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      dist[i][j] = -1;
      f[i][j] = -1;
      b[i][j] = s[j];
      if (s[j] == 'S')
        start = {i, j};
      else if (s[j] == 'D')
        end = {i, j};
      else if (s[j] == '*') {
        q.push({{i, j}, 0});
        f[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    pii cur = q.front().first;
    int x = cur.first;
    int y = cur.second;
    int d = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dxys[i].first;
      int ny = y + dxys[i].second;

      if (in_bound(nx, ny) && b[nx][ny] != 'D' && b[nx][ny] != 'X' && f[nx][ny] == -1) {
        f[nx][ny] = d + 1;
        q.push({{nx, ny}, d + 1});
      }
    }
  }

  f[end.first][end.second] = 1e9;
  dist[start.first][start.second] = 0;

  q.push({start, 0});
  int ans = -1;
  while (!q.empty()) {
    pii cur = q.front().first;
    int x = cur.first;
    int y = cur.second;
    int d = q.front().second;
    q.pop();

    if (b[x][y] == 'D')
      ans = d;

    for (int i = 0; i < 4; i++) {
      int nx = x + dxys[i].first;
      int ny = y + dxys[i].second;

      if (in_bound(nx, ny) && b[nx][ny] != 'X' && (f[nx][ny] == -1 || f[nx][ny] > d + 1) && dist[nx][ny] == -1) {
        dist[nx][ny] = d + 1;
        q.push({{nx, ny}, d + 1});
      }
    }
  }

  if (ans == -1) {
    cout << "KAKTUS" << nl;
  } else {
    cout << ans << nl;
  }

  return 0;
}
