#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int t[505][505];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      t[i][j] = 0;
    }
  }


  for (int i = 1; i <=n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> t[i][j];
      t[i][j] += max(t[i - 1][j - 1], t[i - 1][j]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, t[n][i]);
  }

  cout << ans;

  return 0;
}
