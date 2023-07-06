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
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (a[n] == 1) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
            int ones = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == 0) {
                    cout << ones << " ";
                    ones = 0;
                } else {
                    cout << 0 << " ";
                    ones++;
                }
            }
            cout << nl;
        }
    }

    return 0;
}
