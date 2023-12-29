#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;
      ll all = 0;
      for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        all += x;
      }

      ll l = 0;
      ll r = 1e9;
      while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (mid * mid <= all)
          l = mid;
        else
          r = mid;
      }

      if (l * l == all)
        cout << "YES" << nl;
      else
        cout << "NO" << nl;

    }

    return 0;
}
