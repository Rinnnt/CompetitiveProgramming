#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      string a, b;
      cin >> a >> b;

      int al = a.size();
      int bl = b.size();

      if (al != bl) {
        cout <<  9 * (max(al, bl) - 1) + (al > bl ? a[0] - '0' : b[0] - '0') << '\n';
      } else {
        ll ans = 0;
        int i;
        for (i = 0; i < al; i++) {
          if (a[i] != b[i]) {
            break;
          }
        }
        ans += abs((a[i] - '0') - (b[i] - '0'));
        ans += max(0, 9 * (al - i - 1));
        cout << ans << '\n';
      }
    }

    return 0;
}
