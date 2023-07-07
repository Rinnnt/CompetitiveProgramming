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
        vector<int> a(n);
        int c = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (c == 0) {
                c = x;
            } else {
                c &= x;
            }
            if (c == 0) {
                ans++;
            }
        }
        cout << max(ans, 1) << nl;
    }

    return 0;
}
