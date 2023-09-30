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
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += 1;
            int a;
            cin >> a;
            if (x == a) {
                x += 1;
            }
        }
        cout << x << nl;
    }

    return 0;
}
