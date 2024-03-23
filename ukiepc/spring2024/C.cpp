#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      ll n, x, y;
      cin >> n >> x >> y;
      x *= 100;
      y *= 100;

      ll change = 0;
      for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll bill = stol(s.substr(0, s.find('.')) + s.substr(s.find('.') + 1, 2));
        change += (y * ((bill + y - 1) / y)) - bill;
      }

      if (change >= x) {
        cout << "YES" << nl;
      } else {
        cout << "NO" << nl;
      }

    }

    return 0;
}
