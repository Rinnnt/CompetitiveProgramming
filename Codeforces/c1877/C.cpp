#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n, m, k;
      cin >> n >> m >> k;
      ll ans = 0;
      if (k == 1) {
        ans = 1;
      } else if (k == 2) {
        if (m >= n) {
          ans = n - 1;
          ans += m / n;
        } else {
          if (m == 0) {
            ans = 0;
          } else {
            ans = m;
          }
        }
      } else if (k == 3) {
        if (n > 1) {
          if (m > n) {
            ans = m - (m / n);
            ans -= n - 1;
          }
        }
      }
      cout << ans << nl;
    }

    return 0;
}
