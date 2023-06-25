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
      ll n;
      cin >> n;

      ll sum = 0;
      while (n) {
        sum += n;
        n >>= 1;
      }

      cout << sum << nl;
    }

    return 0;
}



/*
 *           1
 *         10   11
 *     100 101 110 111
*/
