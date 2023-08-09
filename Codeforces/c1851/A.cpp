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
        ll n, m, k, h;
        cin >> n >> m >> k >> h;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (abs(x - h) != 0 && abs(x - h) % k == 0 && abs(x - h) / k < m) {
                ans++;
            }
        }
        
        cout << ans << nl;
    }

    return 0;
}
