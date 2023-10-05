#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

const int N = 5001;
int a[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < N; i++) {
            a[i] = 0;
            dp[i] = 1e9;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < N) {
                a[x]++;
            }
        }

        int mex = 0;
        while (a[mex]) {
            mex++;
        }

        dp[mex] = 0;

        for (int i = mex; i >= 1; i--) {
            for (int j = 0; j < i; j++) { 
                dp[j] = min(dp[j], dp[i] + i * (a[j] - 1) + j);
            }
        }

        cout << dp[0] << nl;
    }

    return 0;
}
