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
        int n;
        cin >> n;
        int d = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == i) {
                d++;
            }
        }

        cout << (d + 1) / 2 << nl;

    }

    return 0;
}
