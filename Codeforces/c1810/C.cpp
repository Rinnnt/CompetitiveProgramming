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
      ll n, c, d;
      cin >> n >> c >> d;

      vector<ll> as(n, 0);
      for (ll i = 0; i < n; i++) {
        cin >> as[i];
      }

      sort(as.begin(), as.end());

      ll missing = as[0] - 1;
      ll toremove = 0;
      ll mcost = (missing * d + (n - 1) * c);
      for (ll i = 1; i < n; i++) {
        if (as[i] == as[i - 1]) {
          toremove++;
        } else if (as[i] > as[i - 1] + 1) {
          missing += as[i] - as[i - 1] - 1;
        }
        mcost = min(missing * d + (n - i - 1 + toremove) * c, mcost);
      }

      // remove everthing and add 1 - [1] case
      if ((d + n * c) < mcost) {
        mcost = d + n * c;
      }
      cout << mcost << nl;
    }

    return 0;
}
