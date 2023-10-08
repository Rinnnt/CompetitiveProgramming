#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      int ans = 0;
      for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        ans -= x;
      }

      cout << ans << nl;

    }

    return 0;
}
