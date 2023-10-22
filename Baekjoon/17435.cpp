#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int sparse_table[25][200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> sparse_table[0][i];
  }

  for (int i = 1; i < 25; i++) {
    for (int j = 0; j < 200001; j++) {
      sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n, x;
    cin >> n >> x;

    for (int j = 24; j >= 0; j--) {
      if ((1 << j) <= n) {
        x = sparse_table[j][x];
        n -= (1 << j);
      }
    }
    cout << x << nl;
  }

  return 0;
}
