#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int d[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = 1e9;
      }
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    if (t < d[u][v]) {
      d[u][v] = t;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == 1e9) {
        cout << 0 << " ";
      } else {
        cout << d[i][j] << " ";
      }
    }
    cout << nl;
  }

  return 0;
}
