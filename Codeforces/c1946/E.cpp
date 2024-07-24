#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 1e9 + 7;

ll fac[200001];

ll binpow(ll n, ll m) {
  ll res = 1;
  while (m) {
    if (m % 2) res = res * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return res;
}

ll comb(ll n, ll r) {
  return fac[n] * binpow(fac[n - r], mod - 2) % mod * binpow(fac[r], mod - 2) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fac[0] = 1;
    for (ll i = 1; i < 200001; i++)
      fac[i] = i * fac[i - 1] % mod;

    ll t;
    cin >> t;
    while (t--) {

      int n, m1, m2;
      cin >> n >> m1 >> m2;

      vector<int> p(m1), s(m2);
      for (auto &x : p) cin >> x;
      for (auto &x : s) cin >> x;

      if (p[0] != 1 || p[m1 - 1] != s[0] || s[m2 - 1] != n) {
        cout << 0 << nl;
      } else {
        ll res = comb(n - 1, s[0] - 1);
        for (int i = m1 - 2; i >= 0; i--)
          res = res * comb(p[i + 1] - 2, p[i + 1] - p[i] - 1) % mod * fac[p[i + 1] - p[i] - 1] % mod;
        for (int i = 1; i < m2; i++)
          res = res * comb(n - s[i - 1] - 1, s[i] - s[i - 1] - 1) % mod * fac[s[i] - s[i - 1] - 1] % mod;
        cout << res << nl;
      }

    }

    return 0;
}
