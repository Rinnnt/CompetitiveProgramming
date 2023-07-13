#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int p[1025][1025];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    p[0][i] = 0;
    p[i][0] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[i][j];
      p[i][j] += p[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      p[i][j] += p[i - 1][j];
    }
  }

  for (int i = 0; i < m; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1] << nl;
  }

  return 0;
}
