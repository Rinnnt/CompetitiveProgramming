#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

ll dp[55][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, c, o, d, l;
    cin >> t >> c >> o >> d >> l;

    int dpi = 0;
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 1005; j++) {
            dp[i][j] = 0;
        }
    }
    dp[dpi][0] = 1;

    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1004 - j; k >= 0; k--) {
                dp[dpi + 1][k + j] += dp[dpi][k];
            }
        }
        dpi++;
    }
    for (int i = 0; i < c; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1004 - j; k >= 0; k--) {
                dp[dpi + 1][k + j] += dp[dpi][k];
            }
        }
        dpi++;
    }
    for (int i = 0; i < o; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = 1004 - j; k >= 0; k--) {
                dp[dpi + 1][k + j] += dp[dpi][k];
            }
        }
        dpi++;
    }
    for (int i = 0; i < d; i++) {
        for (int j = 1; j <= 12; j++) {
            for (int k = 1004 - j; k >= 0; k--) {
                dp[dpi + 1][k + j] += dp[dpi][k];
            }
        }
        dpi++;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1004 - j; k >= 0; k--) {
                dp[dpi + 1][k + j] += dp[dpi][k];
            }
        }
        dpi++;
    }

    vector<pair<ll, ll>> res;
    for (int i = 0; i < 1005; i++) {
        if (dp[dpi][i]) {
            res.push_back({dp[dpi][i], i});
        }
    }
    sort(res.rbegin(), res.rend());

    for (auto x : res) {
        cout << x.second << " ";
    }
    cout << nl;

    return 0;
}
