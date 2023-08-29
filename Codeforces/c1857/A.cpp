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
        int odds = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                odds++;
            }
        }

        cout << (odds % 2 == 0 ? "YES" : "NO") << nl;
    }

    return 0;
}
