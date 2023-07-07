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
        ll n, k;
        cin >> n >> k;
        vector<int> a;
        ll prev, cur;
        cin >> prev;
        for (int i = 0; i < n - 1; i++) {
            cin >> cur;
            a.push_back(abs(cur - prev));
            prev = cur;
        }

        sort(a.begin(), a.end());

        ll sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += a[i];
        }

        cout << sum << nl;
    }

    return 0;
}
