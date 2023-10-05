#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<int> b(m);
        for (auto &x : b) {
            cin >> x;
        }

        k = (k % 2);
        if (k == 0) {
            k += 2;
        }

        for (int i = 1; i <= k; i++) {
            if (i % 2) {
                int mina = 1e9;
                int minaidx = -1;
                int maxb = 1;
                int maxbidx = -1;
                for (int j = 0; j < n; j++) {
                    if (a[j] < mina) {
                        mina = a[j];
                        minaidx = j;
                    }
                }
                for (int j = 0; j < m; j++) {
                    if (b[j] > maxb) {
                        maxb = b[j];
                        maxbidx = j;
                    }
                }
                if (mina < maxb) {
                    a.erase(a.begin() + minaidx);
                    b.erase(b.begin() + maxbidx);
                    a.push_back(maxb);
                    b.push_back(mina);
                }
            } else {
                int minb = 1e9;
                int minbidx = -1;
                int maxa = 1;
                int maxaidx = -1;
                for (int j = 0; j < m; j++) {
                    if (b[j] < minb) {
                        minb = b[j];
                        minbidx = j;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (a[j] > maxa) {
                        maxa = a[j];
                        maxaidx = j;
                    }
                }
                if (minb < maxa) {
                    a.erase(a.begin() + maxaidx);
                    b.erase(b.begin() + minbidx);
                    a.push_back(minb);
                    b.push_back(maxa);
                }
            }
        }

        ll ans = 0;
        for (auto x : a) {
            ans += x;
        }
        cout << ans << nl;
    }

    return 0;
}
