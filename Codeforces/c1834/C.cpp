#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      string s, t;
      cin >> s >> t;

      ll diff = 0;
      ll revdiff = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
          diff++;
        }
        if (s[i] != t[n - i - 1]) {
          revdiff++;
        }
      }

      ll ans = 99999999;
      if (diff % 2 == 0) {
        if (diff == 0) {
          ans = 0;
        } else {
          ans = min(2 * diff, ans);
        }
      } else {
        ans = min(2 * diff - 1, ans);
      }

      if (revdiff % 2 == 0) {
        if (revdiff == 0) {
          ans = min(2LL, ans);
        } else {
          ans = min(2 * revdiff - 1, ans);
        }
      } else {
        ans = min(2 * revdiff, ans);
      }

      cout << ans << '\n';
    }

    return 0;
}
