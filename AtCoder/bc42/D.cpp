#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 1e9 + 7;

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

  int h, w, a, b;
  cin >> h >> w >> a >> b;

  fact[0] = 1;
  for (int i = 1; i <= h + w - 2; i++)
    fact[i] = fact[i - 1] * i % mod;

  /*
   *  .......
   *  .......
   *  xxx....
   *  xxx....
   *
   *  fix the row in which the path crosses the column b -> b + 1.
   *  every path must cross this column at one point, and only once.
   *  Count the number of total paths by summing product of:
   *  paths that get from start to (i, b)
   *  and paths that go from (i, b + 1) to end
   *
   */

  ll ans = 0;
  for (int i = 1; i <= h - a; i++) {
    ans += comb(i - 1 + b - 1, i - 1) * comb(h - i + w - b - 1, h - i) % mod;
    ans %= mod;
  }

  cout << ans << nl;

  return 0;
}

