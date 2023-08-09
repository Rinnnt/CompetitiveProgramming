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
        ll n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (auto &x : c) {
            cin >> x;
        }

        bool possible = false;
        if (c[0] == c[n - 1]) {
            int count = 2;
            for (int i = 1; i < n - 1; i++) {
                if (c[i] == c[0]) {
                    count++;
                }
            }
            if (count >= k) {
                possible = true;
            }
        } else {
            bool first = true;
            int lc = 1;
            int rc = 1;
            for (int i = 1; i < n - 1; i++) {
                if (lc < k) {
                    if (c[i] == c[0]) {
                        lc++;
                    }
                } else {
                    if (c[i] == c[n - 1]) {
                        rc++;
                    }
                }
            }
            if (lc >= k && rc >= k) {
                possible = true;
            }
        }

        cout << (possible ? "YES" : "NO") << nl;

    }

    return 0;
}
