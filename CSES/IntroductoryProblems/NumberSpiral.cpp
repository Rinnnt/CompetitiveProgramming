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
      ll y, x;
      cin >> y >> x;
      ll ma = max(x, y);
      ll num = ma * (ma - 1) + 1;
      if (y == x) {
        cout << num << nl;
      } else if (y < x) {
        if (x % 2 == 0) {
          cout << num - (x - y) << nl;
        } else {
          cout << num + (x - y) << nl;
        }
      } else {
        if (y % 2 == 0) {
          cout << num + (y - x) << nl;
        } else {
          cout << num - (y - x) << nl;
        }
      }
    }

    return 0;
}