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
      ll a, b;
      cin >> a >> b;
      if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
        cout << "YES" << nl;
      } else {
        cout << "NO" << nl;
      }

    }


    return 0;
}