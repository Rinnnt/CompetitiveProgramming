#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll mod;

ll modpow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m % 2) ans = ans * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ans;
}

ll modpowsum(ll a, ll x) {
  if (x == 1) return 1;

  if (x % 2) {
    return (modpow(a, x - 1) + modpowsum(a, x - 1)) % mod;
  } else {
    ll m = modpowsum(a, x / 2);
    return (m + (modpow(a, x / 2) * m % mod)) % mod;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll a, x;
  cin >> a >> x >> mod;
  a = a % mod;
  if (mod == 1) {
    cout << 0 << nl;
    return 0;
  }

  cout << modpowsum(a, x) << nl;

  return 0;
}

