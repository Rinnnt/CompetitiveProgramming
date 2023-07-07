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
        ll x;
        set<ll> xs;
        xs.insert(0);
        ll cur = 0;
        ll m = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            cur ^= x;
            xs.insert(cur);
            for (auto p : xs) {
                m = max(cur ^ p, m);
            }
        }
        cout << m << nl;
    }

    return 0;
}
