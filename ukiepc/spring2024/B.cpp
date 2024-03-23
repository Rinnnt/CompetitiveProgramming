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

      int x, y, z;
      cin >> x >> y >> z;

      if (x > 0 && y > 0) {
        if (z > 0) {
          cout << "YES" << nl;
        } else {
          cout << "NO" << nl;
        }
      } else {
        cout << "YES" << nl;
      }

    }

    return 0;
}
