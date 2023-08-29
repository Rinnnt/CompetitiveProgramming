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
        vector<ll> b((n * (n - 1)) / 2);
        for (auto &x : b) {
            cin >> x;
        }
        sort(b.begin(), b.end());
        int idx = -1;
        n--;
        while (n > 0) {
            idx += n;
            cout << b[idx] << " ";
            n--;
        }
        
        cout << (int)1e9 << nl;
    }

    return 0;
}
