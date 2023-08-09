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
        vector<ll> a(n + 1);
        map<ll, deque<int>> index;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            index[a[i]].push_back(i);
        }
        sort(a.begin(), a.end());
        ll minx = 1e15;
        ll mina, minb;
        for (int i = 1; i < n; i++) {
            if ((a[i] ^ a[i + 1]) < minx) {
                minx = a[i] ^ a[i + 1];
                mina = a[i];
                minb = a[i + 1];
            }
        }

        ll x = 0;
        for (int i = k - 1; i >= 0; i--) {
            x |= 1 - ((mina >> i) & 1);
            x <<= 1;
        }
        x >>= 1;
        int mini = index[mina].front();
        index[mina].pop_front();
        int minj = index[minb].front();

        cout << mini << " " << minj << " " << x << nl;

    }

    return 0;
}
