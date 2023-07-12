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
        if (n == 1) {
            cout << 1 << nl;
            continue;
        }
        if (n == 2) {
            cout << "2 1" << nl;
            continue;
        }
        if (n == 3) {
            cout << "2 1 3" << nl;
            continue;
        }
        vector<int> a(n);
        a[0] = 2;
        a[n / 2] = 1;
        a[n - 1] = 3;
        for (int i = 1; i < n / 2; i++) {
            a[i] = i + 3;
        }
        for (int i = n - 2; i > n / 2; i--) {
            a[i] = i + 2; 
        }

        for (auto x : a) {
            cout << x << " ";
        }
        cout << nl;

    }

    return 0;
}
