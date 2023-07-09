#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int m, n, k;
int farm[51][51];

int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};

void dfs(int y, int x) {
  farm[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    if (farm[y + dy[i]][x + dx[i]] == 1) {
      dfs(y + dy[i], x + dx[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        farm[i][j] = 0;
      }
    }
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      farm[y][x] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (farm[i][j] == 1) {
          ans++;
          dfs(i, j);
        }
      }
    }
    cout << ans << nl;
  }

}
