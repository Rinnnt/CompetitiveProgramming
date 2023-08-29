#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      a[i].first = max(0, (y - x + 1) / 2);
      a[i].second = z;
      total += z;
    }

    vector<ll> dp(total + 1, 1e12);
    dp[0] = 0;

    ll ans = 1e12;
    for (auto x : a) {
      for (int i = total; i >= x.second; i--) {
        dp[i] = min(dp[i], dp[i - x.second] + x.first);
      }
    }
    for (int i = (total + 1) / 2; i <= total; i++) {
      ans = min(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
