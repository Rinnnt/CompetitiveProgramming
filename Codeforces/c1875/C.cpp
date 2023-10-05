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
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        if (n % m == 0) {
            ans = 0;
        } else {
            n = n % m;
            ll p;
            for (p = (1LL << 31); p > 0; p >>= 1) {
                if (m % p == 0 && (n % (m / p) == 0)) {
                    break;
                }
            }
            if (p == 0) {
                ans = -1;
            } else {
                ll k = m / p;
                m = p;
                n /= k;
                for (int i = 0; i < 32; i++) {
                    if ((n >> i) & 1) {
                        ans += ((m / (1 << i)) - 1) * (1 << i);
                    }
                }
                ans *= k;
            }
        }
        cout << ans << nl;
    }

    return 0;
}
