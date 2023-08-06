#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll m = 0;
        for (auto &x : a) {
            cin >> x;
            m = max(m, x);
        }

        ll l = 0;
        ll r = m + k + 1;
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            bool possible = false;
            for (int i = 0; i < n; i++) {
                ll cur = mid;
                ll k_used = 0;
                for (int j = i; j < n; j++) {
                    if (cur <= a[j]) {
                        break;
                    }

                    if (j + 1 == n) {
                        k_used += k + 1;
                        break;
                    }

                    k_used += cur - a[j];
                    cur--;
                }
                if (k_used <= k) {
                    possible = true;
                }
            }
            if (possible) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << l << nl;

    }

    return 0;
}
