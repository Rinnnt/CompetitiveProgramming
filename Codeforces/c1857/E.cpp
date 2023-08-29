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
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());

        map<int, ll> res;
        for (int i = 0; i < n; i++) {
            res[b[0]] += abs(b[0] - b[i]) + 1;
        }
        for (int i = 1; i < n; i++) {
            ll diff = b[i] - b[i - 1];
            res[b[i]] = res[b[i - 1]] + (i - 1) * diff - (n - i - 1) * diff;
        }

        for (auto x : a) {
            cout << res[x] << " ";
        }
        cout << nl;
    }

    return 0;
}
