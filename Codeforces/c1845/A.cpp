#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES" << nl;
            cout << n << nl;
            for (int i = 0; i < n; i++) {
                cout << "1 ";
            }
            cout << nl;
        } else {
            if (k == 1) {
                cout << "NO" << nl;
            } else if (k == 2) {
                if (n % 2 == 0) {
                    cout << "YES" << nl;
                    cout << (n / 2) << nl;
                    for (int i = 0; i < (n / 2); i++) {
                        cout << "2 ";
                    }
                    cout << nl;
                } else {
                    cout << "NO" << nl;
                }
            } else {
                if (n == 1) {
                    cout << "NO" << nl;
                } else {
                    cout << "YES" << nl;
                    cout << n / 2 << nl;
                    if (n % 2 == 1) {
                        cout << "3 " << nl;
                    } else {
                        cout << "2 " << nl;
                    }
                    for (int i = 1; i < n / 2; i++) {
                        cout <<  "2 " << nl;
                    }
                }
            }
        }
    }

    return 0;
}
