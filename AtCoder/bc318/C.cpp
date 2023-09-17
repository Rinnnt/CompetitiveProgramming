#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d, p;
    cin >> n >> d >> p;

    ll ans = 0;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        ans += f[i];
    }

    sort(f.begin(), f.end());
    int idx = n - 1;
    while (idx >= 0) {
        int cnt = 0;
        ll sum = 0;
        while (idx >= 0 && cnt < d) {
            sum += f[idx--];
            cnt++;
        }
        if (sum > p) {
            ans -= sum;
            ans += p;
        }
    }

    cout << ans;

    return 0;
}
