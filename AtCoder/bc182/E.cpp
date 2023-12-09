#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int lit = 0;
int b[1501][1501] = {};
pii bulbs[500001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, w, n, m;
  cin >> h >> w >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> bulbs[i].first >> bulbs[i].second;

  for (int i = 0; i < m; i++) {
    int c, d;
    cin >> c >> d;
    b[c][d] = 3;
  }

  for (int i = 0; i < n; i++) {
    int x = bulbs[i].first;
    int y = bulbs[i].second;

    if (b[x][y] == 0) {
      b[x][y] = 3;
      lit++;
    }

    int nx = x - 1;
    while (nx > 0 && (b[nx][y] & 1) == 0) {
      if (b[nx][y] == 0) lit++;
      b[nx][y] |= 1;
      nx--;
    }
    nx = x + 1;
    while (nx <= h && (b[nx][y] & 1) == 0) {
      if (b[nx][y] == 0) lit++;
      b[nx][y] |= 1;
      nx++;
    }
    int ny = y - 1;
    while (ny > 0 && (b[x][ny] & 2) == 0) {
      if (b[x][ny] == 0) lit++;
      b[x][ny] |= 2;
      ny--;
    }
    ny = y + 1;
    while (ny <= w && (b[x][ny] & 2) == 0) {
      if (b[x][ny] == 0) lit++;
      b[x][ny] |= 2;
      ny++;
    }
  }

  cout << lit << nl;

  return 0;
}

