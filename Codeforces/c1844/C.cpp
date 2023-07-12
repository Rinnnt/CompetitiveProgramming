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
        ll n;
        cin >> n;
        vector<ll> a(n);
        bool pos = false;
        ll m = -1e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m = max(m, a[i]);
            if (a[i] > 0) {
                pos = true;
            }
        }


        if (!pos) {
            cout << m << nl;
        } else {
            ll ans1 = 0;
            for (int i = 0; i < n; i += 2) {
                if (a[i] > 0) {
                    ans1 += a[i];
                }
            }
            ll ans2 = 0;
            for (int i = 1; i < n; i += 2) {
                if (a[i] > 0) {
                    ans2 += a[i];
                }
            }

            cout << max(ans1, ans2) << nl;
        }
    }

    return 0;
}
