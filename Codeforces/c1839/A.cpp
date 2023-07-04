#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n, k;
      cin >> n >> k;
      ll res = 0;
      for (ll i = 1; i <= n; i++) {
        res = max((2 * ((i + k - 1) / k)) - max(2 * i - n, 0LL), res);
      }
      cout << res << nl;
    }

    return 0;
}
