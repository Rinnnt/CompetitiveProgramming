#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int ans = 64;
  for (int i = 0; i + 8 <= n; i++) {
    for (int j = 0; j + 8 <= m; j++) {
      char even = a[i][j];
      int wrong = 0;
      for (int dx = 0; dx < 8; dx++) {
        for (int dy = 0; dy < 8; dy++) {
          if ((dx + dy) % 2 == 0) {
            if (a[i + dx][j + dy] != even) {
              wrong++;
            }
          } else {
            if (a[i + dx][j + dy] == even) {
              wrong++;
            }
          }
        }
      }
      ans = min(wrong, ans);
      ans = min(64 - wrong, ans);
    }
  }
  cout << ans << nl;

}
