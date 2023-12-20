#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

ll fact[400005];

int a[400005] = {};

ll modPow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m & 1) ans = (ans * n) % mod;
    n = (n * n) % mod;
    m >>= 1;
  }
  return ans;
}

ll binom(ll n, ll r) {
  return (((fact[n] * modPow(fact[r], mod - 2)) % mod) * modPow(fact[n - r], mod - 2)) % mod;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for (int i = 1; i < 400005; i++)
    fact[i] = (i * fact[i - 1]) % mod;

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }

  ll res = 0;
  ll need = 1;
  for (int i = 0; i < n + k; i++) {
    if (need > k) break;
    ll rest = k - need;
    res = (res + binom(rest + i, i)) % mod;
    if (!a[i]) need++;
  }

  cout << res << nl;

  return 0;
}

