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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &x : a) {
            cin >> x;
        }
        for (auto &x : b) {
            cin >> x;
        }
        bool same = true;
        int r = -1;
        for (int i = 0; i < n; i++) {
            int p = a[i];
            int q = b[i];
            int turns = 0;
            if (p < q) {
                int temp = p;
                p = q;
                q -= temp;
                turns++;
            }
            while (q != 0) {
                int n = p / q;
                turns += n + (n - 1) / 2;
                if (n % 2) {
                    int temp = p;
                    p = q;
                    q = temp % q;
                } else {
                    int temp = p;
                    p = q + temp % q;
                    q = temp % q;
                }
            }
            if (a[i] == 0 && b[i] == 0) {
                continue;
            } else {
                if (r == -1 || turns % 3 == r) {
                    r = turns % 3;
                } else {
                    same = false;
                    break;
                }
            }
        }

        if (same) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }

    }

    return 0;
}
