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
        vector<int> o;
        vector<int> e;
        vector<int> p;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            p.push_back(x % 2);
            if (x % 2) {
                o.push_back(x);
            } else {
                e.push_back(x);
            }
        }
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());

        int oi = 0;
        int ei = 0;
        bool possible = true;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int next;
            if (p[i]) {
                next = o[oi++];
            } else {
                next = e[ei++];
            }
            if (next < prev) {
                possible = false;
                break;
            }
            prev = next;
        }

        cout << (possible ? "YES" : "NO") << nl;
    }

    return 0;
}
