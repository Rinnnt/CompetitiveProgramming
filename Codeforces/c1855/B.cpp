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
        ll a = 2;
        while (n % a == 0) {
            a++;
        }
        cout << a - 1 << nl;
    }

    return 0;
}
