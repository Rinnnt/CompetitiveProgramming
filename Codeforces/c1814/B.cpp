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

      int a, b;
      cin >> a >> b;
      int ans = a + b;
      for (int m = 2; m < 100000; m++) {
        ans = min(ans , (a + m - 1) / m + (b + m - 1) / m + m - 1);
      }

      cout << ans << nl;
    }

    return 0;
}
