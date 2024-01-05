#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int h, w;
char b[2001][2001];
vector<pii> t[26];
int dist[2001][2001];
int tused[26];

vector<pii> dxys = {
  {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool inBounds(int x, int y) {
  return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> h >> w;

  pii start, end;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      b[i][j] = s[j];
      if (b[i][j] == 'S') start = {i, j};
      else if (b[i][j] == 'G') end = {i, j};
      else if (b[i][j] != '.' && b[i][j] != '#') t[b[i][j] - 'a'].push_back({i, j});
      dist[i][j] = 1e9;
    }
  }

  deque<pii> q;
  q.push_back(start);
  dist[start.first][start.second] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();

    for (auto dxy : dxys) {
      int nx = x + dxy.first;
      int ny = y + dxy.second;
      if (inBounds(nx, ny) && dist[nx][ny] > dist[x][y] + 1 && b[nx][ny] != '#') {
        dist[nx][ny] = dist[x][y] + 1;
        q.push_back({nx, ny});
      }
    }
    if (b[x][y] - 'a' >= 0 && b[x][y] - 'a' < 26 && !tused[b[x][y] - 'a']) {
      tused[b[x][y] - 'a'] = true;
      for (auto tp : t[b[x][y] - 'a']) {
        if (dist[tp.first][tp.second] > dist[x][y] + 1) {
          dist[tp.first][tp.second] = dist[x][y] + 1;
          q.push_back({tp.first, tp.second});
        }
      }
    }
  }

  cout << (dist[end.first][end.second] == 1e9 ? -1 : dist[end.first][end.second]) << nl;

  return 0;
}

