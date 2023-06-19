#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll A, B, C, k;
      cin >> A >> B >> C >> k;

      if (C < max(A, B) || C > max(A, B) + 1) {
        cout << "-1" << '\n';
        continue;
      }

      ll bmin = pow(10, B - 1);
      ll bmax = pow(10, B) - 1;

      ll cmin = pow(10, C - 1);
      ll cmax = pow(10, C) - 1;

      ll a;
      ll amax = pow(10, A) - 1;

      ll l = pow(10, A - 1) - 1;
      ll r = pow(10, A);
      while (l + 1 < r) {
        ll mid = (l + r) / 2;

        if (mid + bmax >= cmin) {
          r = mid;
        } else {
          l = mid;
        }
      }
      a = r;

      while (k > 0 && a <= amax) {
        ll range = min(a + bmax, cmax) - max(a + bmin, cmin) + 1;
        if (range >= k) {
          cout << a << " + " << (ll)(max(a + bmin, cmin) - a + k - 1) << " = " << (ll)(max(a + bmin, cmin) + k - 1) << '\n';
          k = 0;
          break;
        } else {
          k -= range;
        }
        a++;
      }
      if (k > 0) {
        cout << "-1" << '\n';
      }
    }

    return 0;
}
