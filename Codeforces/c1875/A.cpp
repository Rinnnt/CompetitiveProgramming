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
        int a, b, n;
        cin >> a >> b >> n;
        ll ans = 0;
        ans += b - 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += min(a - 1, x);
        }
        ans += 1;
        cout << ans << nl;
    }

    return 0;
}
