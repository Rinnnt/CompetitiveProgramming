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
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            cout << n + 1 - x << " ";
        }
        cout << nl;
    }

    return 0;
}
