#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

ll mod = 1e9 + 7;
ll fact[1000001];

ll n, h;
map<pair<ll, ll>, ll> memo;
ll k[5001] = {};
ll pref[5001] = {};

ll solve(ll n, ll h) {
  if (h < 5001 && n == pref[h]) {
    return 0;
  }

  if (memo.count({n, h})) {
    return memo[{n, h}];
  }

  ll ans = fact[n];

  for (int i = 1; i <= h; i++) {
    ll others = fact[n - pref[i]];
    ll forbidden = solve(pref[i], i - 1);
    ans -= ((others * forbidden) % mod);
    ans = (ans + mod) % mod;
  }
  return memo[{n, h}] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memo.clear();

    fact[0] = 1;
    for (ll i = 1; i < 1000001; i++) {
      fact[i] = (i * fact[i - 1]) % mod;
    }

    pref[0] = 0;
    cin >> n >> h;
    for (int i = 1; i <= h; i++) {
      cin >> k[i];
      pref[i] = pref[i - 1] + k[i];
    }

    cout << solve(n, h) << nl;

    return 0;
}
