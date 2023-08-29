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
        map<ll, ll> a;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a[x]++;
        }

        ll q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            ll x, y;
            cin >> x >> y;
            ll det = x * x - 4 * y;
            if (det >= 0) {
                ll sqdet = sqrt(det);
                if (sqdet * sqdet == det) {
                    ll sola = (x + sqdet) / 2;
                    ll solb = (x - sqdet) / 2;
                    if (sola + solb == x && sola * solb == y) {
                        if (sola == solb) {
                            cout << (a[sola] * (a[solb] - 1)) / 2 << " ";
                        } else {
                            cout << a[sola] * a[solb] << " ";
                        }
                    } else {
                        cout << 0 << " ";
                    }
                } else {
                    cout << 0 << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << nl;
    }

    return 0;
}
