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
      ll m = n / 2;
      ll ones = (m + k - 1) / k;
      ll res = 2 * ones;
      ll l = 1 + k * (ones - 1);
      ll r = n - k * (ones - 1);
      if (r - l > k) {
        res++;
      }
      cout << res << nl;
    }

    return 0;
}
