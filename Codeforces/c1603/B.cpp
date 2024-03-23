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

      ll x, y;
      cin >> x >> y;

      if (x > y)
        cout << x + y << nl;
      else if (x == y)
        cout << x << nl;
      else
        cout << y - (y % x) / 2 << nl;

    }

    return 0;
}
