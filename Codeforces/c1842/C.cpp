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

      ll a;
      vector<ll> m(n+1, -1e9);
      vector<ll> dp(n + 1, 0);
      for (ll i = 1; i < n + 1; i++) {
        cin >> a;
        dp[i] = max(dp[i - 1], m[a] + i);
        m[a] = max(m[a], dp[i - 1] - (i - 1));
      }

      cout << dp[n] << nl;

    }

    return 0;
}
