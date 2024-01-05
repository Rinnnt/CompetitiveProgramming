#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 998244353;

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

  int n, m, k;
  cin >> n >> m >> k;

  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }

  ll ans = 0;
  for (int p = 0; p <= k; p++) {
    ans += comb(n - 1, p) * m % mod * modpow(m - 1, n - 1 - p) % mod;
    ans %= mod;
  }
  cout << ans << nl;

  return 0;
}

