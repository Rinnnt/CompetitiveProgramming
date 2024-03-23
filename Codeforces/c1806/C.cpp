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

      vector<ll> ps(2 * n);
      ll ans = 0;
      ll sum = 0;
      for (auto &p : ps) {
        cin >> p;
        ans += abs(p);
        sum += abs(p - (-1));
      }

      if (n == 1) {
        ans = min(ans, abs(ps[0] - ps[1]));
      }
      if (n == 2) {
        ans = min(ans, abs(ps[0] - 2) + abs(ps[1] - 2) + abs(ps[2] - 2) + abs(ps[3] - 2));
      }
      if (n % 2 == 0) {
        for (int i = 0; i < 2 * n; i++) {
          ans = min(ans, sum - abs(ps[i] - (-1)) + abs(ps[i] - n));
        }
      }
      cout << ans << nl;

    }

    return 0;
}
