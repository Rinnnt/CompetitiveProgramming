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
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            if (a > b) {
                ans++;
            }
        }
        cout << ans << nl;

    }

    return 0;
}
