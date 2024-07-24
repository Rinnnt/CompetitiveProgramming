#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const int nmax = 302;

int n;
int ts[30];
int visited[nmax][nmax] = {};
bool memo[nmax][nmax][8][30] = {};

const int num_dirs = 8;
pii dirs[8] = {
  {0, 1},
  {1, 1},
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
};

void solve(int x, int y, int d, int i) {
  if (i >= n) return;
  if (memo[x][y][d][i]) return;

  memo[x][y][d][i] = true;
  int dx = dirs[d].first;
  int dy = dirs[d].second;
  for (int k = 0; k < ts[i]; k++) {
    x += dx;
    y += dy;
    visited[x][y] = true;
  }
  solve(x, y, (d + 1) % num_dirs, i + 1);
  solve(x, y, (d + num_dirs - 1) % num_dirs, i + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) cin >> ts[i];

  solve(150, 150, 0, 0);

  int ans = 0;
  for (int i = 0; i < nmax; i++)
    for (int j = 0; j < nmax; j++)
      if (visited[i][j])
        ans++;

  cout << ans << nl;

  return 0;
}
