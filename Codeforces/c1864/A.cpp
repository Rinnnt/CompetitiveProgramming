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
        int x, y, n;
        cin >> x >> y >> n;

        if (x > y || ((n - 1) * (n)) / 2 > y - x) {
            cout << -1 << nl;
        } else {
            vector<int> a(n);
            a[0] = x;
            a[n - 1] = y;
            int diff = 1;
            for (int i = n - 2; i > 0; i--) {
                a[i] = a[i + 1] - diff;
                diff++;
            }

            for (auto x : a) {
                cout << x << " ";
            }
            cout << nl;
        }

    }

    return 0;
}
