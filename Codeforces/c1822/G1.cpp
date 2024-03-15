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
      vector<ll> as(n);
      for (auto &a : as) cin >> a;

      sort(as.begin(), as.end());

      ll ans = 0;
      for (int i = 0; i < n; i++) {
        vector<ll> divs;
        for (int j = 1; j * j <= as[i]; j++) {
          if (as[i] % j == 0) {
            divs.push_back(j);
            if (j != as[i] / j)
              divs.push_back(as[i] / j);
          }
        }

        for (auto div : divs) {
          if (as[i] * div > 1000000) continue;
          if (div == 1) {
            int li = lower_bound(as.begin(), as.end(), as[i]) - as.begin();
            int hi = upper_bound(as.begin(), as.end(), as[i]) - as.begin();
            int x = hi - li;
            if (x >= 3) {
              ans += (x - 1) * 1LL * (x - 2);
            }
          } else {
            int li = lower_bound(as.begin(), as.begin() + i, as[i] / div) - as.begin();
            int hi = upper_bound(as.begin(), as.begin() + i, as[i] / div) - as.begin();
            int lj = lower_bound(as.begin() + i, as.end(), as[i] * div) - as.begin();
            int hj = upper_bound(as.begin() + i, as.end(), as[i] * div) - as.begin();
            ans += (hi - li) * 1LL * (hj - lj);
          }
        }
      }

      cout << ans << nl;
    }

    return 0;
}
