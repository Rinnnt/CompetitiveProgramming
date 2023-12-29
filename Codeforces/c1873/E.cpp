#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      ll n, x;
      cin >> n >> x;
      vector<ll> h(n);
      for (int i = 0; i < n; i++) {
        cin >> h[i];
      }
      sort(h.begin(), h.end());
      vector<ll> p(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + h[i - 1];
      }

      ll l = 0, r = 1e12;
      while (l + 1 < r) {
        ll mid = (l + r) / 2;

        int idx = lower_bound(h.begin(), h.end(), mid) - h.begin();
        ll required = mid * 1LL * idx - p[idx];
        if (required <= x) {
          l = mid;
        } else {
          r = mid;
        }
      }

      cout << l << nl;

    }

    return 0;
}
