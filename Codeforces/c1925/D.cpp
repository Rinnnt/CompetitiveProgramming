#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const int mod = 1e9 + 7;

ll fact[200001];

ll modpow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m % 2) ans = ans * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ans;
}

ll comb(ll n, ll r) {
  return fact[n] * modpow(fact[n - r], mod - 2) % mod * modpow(fact[r], mod - 2) % mod;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for (int i = 1; i < 200001; i++)
    fact[i] = i * fact[i - 1] % mod;

  ll t;
  cin >> t;
  while (t--) {

    ll n, m, k;
    cin >> n >> m >> k;

    ll sum = 0;
    for (int i = 0; i < m; i++) {
      ll a, b, f;
      cin >> a >> b >> f;
      sum = (sum + f) % mod;
    }

    ll all = (n * (n - 1)) / 2 % mod;
    ll all_inv = modpow(all, mod - 2);
    ll base = (sum * k % mod) * all_inv % mod;
    ll avg_inc = 0;
    for (ll i = 1; i <= k; i++) {
      ll sum = (i * (i - 1)) / 2 % mod;
      ll prob = comb(k, i) * modpow(all_inv, i) % mod * modpow((all - 1) * all_inv % mod, k - i) % mod;
      avg_inc = (avg_inc + sum * prob % mod) % mod;
    }

    cout << (base + m * avg_inc % mod) % mod << nl;
  }

  return 0;
}
