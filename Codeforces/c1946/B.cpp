#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const int mod = 1e9 + 7;

ll modpow(ll n, ll m) {
  ll res = 1;
  while (m) {
    if (m % 2) res = res * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, k;
      cin >> n >> k;

      ll tot = 0;
      vector<ll> as(n);
      for (auto &a : as) {
        cin >> a;
        tot += a;
      }

      ll ms = 0;
      ll sum = 0;
      for (int i = 0; i < n; i++) {
        sum += as[i];
        ms = max(ms, sum);
        sum = max(sum, 0LL);
      }

      ll mult = modpow(2LL, k) - 1;
      ll ans = (tot + (ms % mod * mult % mod)) % mod;
      cout << (ans + mod) % mod << nl;

    }

    return 0;
}
