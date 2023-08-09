#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

#define BLANK 0
#define CHEESE 1
#define OUTSIDE 3
#define MELT 5

int tray[101][101];
pair<int, int> dxys[] = {
  {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  
  int cheese = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tray[i][j];
      if (tray[i][j] == CHEESE) {
        cheese++;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  tray[0][0] = OUTSIDE;
  int hours = 0;
  while (cheese > 0) {
    while (!q.empty()) {
      pair<int, int> c = q.front();
      q.pop();
      for (auto x : dxys) {
        int ni = c.first + x.first;
        int nj = c.second + x.second;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && tray[ni][nj] == BLANK) {
          tray[ni][nj] = OUTSIDE;
          q.push({ni, nj});
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (tray[i][j] == CHEESE) {
          int adj = 0;
          for (auto x : dxys) {
            int ni = i + x.first;
            int nj = j + x.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && tray[ni][nj] == OUTSIDE) {
              adj++;
            }
          }
          if (adj >= 2) {
            tray[i][j] = MELT;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (tray[i][j] == MELT) {
          tray[i][j] = OUTSIDE;
          q.push({i, j});
          cheese--;
        }
      }
    }
    hours++;
  }

  cout << hours;

  return 0;
}
