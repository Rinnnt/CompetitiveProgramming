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
        ll k = 2;
        ll c;
        bool found = false;
        while ((c = 1 + k + k * k) <= 1000000) {
            ll exp = 3;
            while (c < n) {
                ll add = 1;
                for (int i = 0; i < exp; i++) {
                    add *= k;
                }
                c += add;
                exp++;
            }
            if (c == n) {
                found = true;
                break;
            }
            k++;
        }
        if (found) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }

    }

    return 0;
}
