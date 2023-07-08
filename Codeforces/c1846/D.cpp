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
        ll n, d, h;
        cin >> n >> d >> h;

        vector<ll> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        double area = 0;
        for (int i = 0; i < n - 1; i++) {
            ll upper = max(0LL, (heights[i] + h) - heights[i + 1]);
            double a = ((double)(d * h)) / 2.0;
            if (upper == 0) {
                area += a;
            } else {
                area += (((((double)(d *upper)) / h) + d) * (h - upper)) / 2.0;
            }
        }
        area += ((double)(d * h)) / 2.0;
        printf("%.8lf\n", area);
    }

    return 0;
}
