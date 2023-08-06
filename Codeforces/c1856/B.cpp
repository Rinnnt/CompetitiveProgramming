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
        ll spare = 0;
        ll ones = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            spare += x - 1;
            if (x == 1) {
                ones++;
            }
        }
        if (n == 1) {
            cout << "NO" << nl;
        } else {
            cout << (spare >= ones ? "YES" : "NO") << nl;
        }

    }

    return 0;
}
