#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool contains[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll weird = -1;
        vector<ll> a(n + 1, 0);
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            contains[i] = false;
        }
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            ll num = a[i] - a[i -1];
            if (num > n || contains[num]) {
                if (weird == -1) {
                    weird = num;
                } else {
                    possible = false;
                }
            } else {
                contains[num] = true;
            }
        }
        if (weird != -1) {
            int m1 = -1;
            int m2 = -1;
            for (int i = 1; i <= n; i++) {
                if (!contains[i]) {
                    if (m1 == -1) {
                        m1 = i;
                    } else if (m2 == -1) {
                        m2 = i;
                    } else {
                        possible = false;
                        break;
                    }
                }
            }
            if (m1 + m2 != weird) {
                possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << nl;
    }

    return 0;
}
