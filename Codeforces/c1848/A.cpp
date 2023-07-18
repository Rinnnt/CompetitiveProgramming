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
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        int v = (x + y) % 2;
        int caught = false;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            if ((x + y) % 2 == v) {
                caught = true;
            }
        }

        if (caught) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }

    }

    return 0;
}
