#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> p(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> p[i];
    }
    p[1] = 0;

    vector<ll> dp(n + 1, -1);
    for (int i = 0; i < m; i++) {
      ll x, y;
      cin >> x >> y;
      dp[x] = max(dp[x], y);
    }

    for (int i = 1; i <= n; i++) {
      dp[i] = max(dp[i], dp[p[i]] - 1);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i] >= 0) {
        ans++;
      }
    }

    cout << ans << nl;
    return 0;
}
