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
            cout << "a" << nl;
            continue;
        }
        if (n == 2) {
            cout << "ab" << nl;
            continue;
        }

        for (int i = 2; i <= 26; i++) {
            if (n % i) {
                for (int j = 0; j < n; j++) {
                    cout << (char)(97 + (j % i));
                }
                cout << nl;
                break;
            }
        }

    }

    return 0;
}
