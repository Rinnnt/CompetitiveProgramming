#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n;
        cin >> n;
        vector<double> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        double l, lr, r, rr;
        l = a[0];
        lr = a[1];
        r = a[n - 2];
        rr = a[n - 1];
        double ans = 0;
        if (n == 5) {
            ans = max((r + rr) / 2 - (l + a[2]) / 2, (a[2] + rr) / 2 - (l + lr) / 2);
        } else {
            ans = (r + rr) / 2 - (l + lr) / 2;
        }

        cout << "Case #" << t << ": " << ans << nl;
    }

    return 0;
}
