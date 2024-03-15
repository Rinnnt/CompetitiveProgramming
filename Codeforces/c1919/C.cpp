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

      int n;
      cin >> n;

      ll x = 1e9;
      ll y = 1e9;
      ll ans = 0;
      for (int i = 1; i <= n; i++) {
        ll z;
        cin >> z;
        if (z <= x) {
          x = z;
        } else if (z > y) {
          x = z;
          ans++;
        } else {
          y = z;
        }

        if (x > y)
          swap(x, y);
      }

      cout << ans << nl;

    }

    return 0;
}
