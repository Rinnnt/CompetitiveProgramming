#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int b = 0;
        int p = 0;
        int s, d, k;
        cin >> s >> d >> k;

        b = 2 * (s + d);
        p = s + 2 * d;

        cout << "Case #" << i << ": ";
        if (b >= k + 1 && p >= k) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}
