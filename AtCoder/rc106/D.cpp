#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

ll modpow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m % 2) ans = ans * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<ll> as(n);
  for (auto &a : as) cin >> a;

  // get combinations nCr
  vector<vector<ll>> cs(k + 1, vector<ll>(k + 1));
  for (int i = 0; i <= k; i++) {
    cs[i][0] = cs[i][i] = 1;
    for (int j = 1; j < i; j++) cs[i][j] = (cs[i - 1][j] + cs[i - 1][j - 1]) % mod;
  }

  // powers[i] = a[i] ^ x
  // power_sum[x] = a[0] ^ x + a[1] ^ x + ... + a[n - 1] ^ x
  vector<ll> power_sum(k + 1, 0);
  vector<ll> powers(n, 1);
  power_sum[0] = n;

  for (int x = 1; x <= k; x++) {
    for (int i = 0; i < n; i++) {
      powers[i] = powers[i] * as[i] % mod;
      power_sum[x] = (power_sum[x] + powers[i]) % mod;
    }

    ll ans = 0;
    ll p2 = modpow(2, x);

    for (int p = 0; p <= x; p++) {
      ans = (ans + (cs[x][p] * power_sum[p] % mod * power_sum[x - p] % mod)) % mod;
    }

    ans = (ans - (p2 * power_sum[x] % mod)) % mod;  // (ai + ai)^x = (2ai)^x = 2^x(ai)^x
    ans = ans * modpow(2, mod - 2) % mod;           // divide ans by 2 using mod inverse
    cout << (ans + mod) % mod << nl;
  }

  return 0;
}
