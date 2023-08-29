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
        ll max = -1e12;
        vector<ll> diff(n + 1);
        vector<int> strongs;
        for (int i = 1; i <= n; i++) {
            cin >> diff[i];
        }
        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            diff[i] -= x;
            if (diff[i] > max) {
                strongs.clear();
                strongs.push_back(i);
                max = diff[i];
            } else if (diff[i] == max) {
                strongs.push_back(i);
            }
        }
        
        cout << strongs.size() << nl;
        for (auto x : strongs) {
            cout << x << " ";
        }
        cout << nl;

    }

    return 0;
}
