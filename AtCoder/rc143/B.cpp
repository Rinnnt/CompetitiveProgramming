#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

ll fact[250001];

ll modPow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m % 2) ans = (ans * n) % mod;
    n = (n * n) % mod;
    m >>= 1;
  }
  return ans;
}

ll combinations(ll n, ll r) {
  return (((fact[n] * modPow(fact[n - r], mod - 2)) % mod) * modPow(fact[r], mod - 2)) % mod;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n;
  cin >> n;

  fact[0] = 1;
  for (int i = 1; i <= n * n; i++)
    fact[i] = (fact[i - 1] * i) % mod;

  ll ans = modPow(n, 2);
  ans = (ans * combinations(modPow(n, 2), 2 * n - 1)) % mod;
  ans = (ans * modPow(fact[n - 1], 2)) % mod;
  ans = (ans * fact[modPow(n - 1, 2)]) % mod;

  cout << (fact[modPow(n, 2)] - ans + mod) % mod << nl;

  return 0;
}

