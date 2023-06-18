#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      ll sum = 0;
      ll mul = 1;
      for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        mul *= x;
      }

      ll ans = 0;
      if (sum < 0) {
        ans += ((0 - sum) + 1) / 2;
      }
      if ((ans % 2 == 0 && mul == -1) || (ans % 2 == 1 && mul == 1)) {
        ans += 1;
      }

      cout << ans << '\n';
    }

    return 0;
}
