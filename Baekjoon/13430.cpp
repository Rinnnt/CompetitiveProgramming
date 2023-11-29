#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

ll mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll k, n;
  cin >> k >> n;

  ll ans = 1;

  for (ll i = n; i <= n + k; i++)
    ans = (ans * i) % mod;

  ll d = 1;
  for (ll i = 1; i <= k + 1; i++)
    d = (d * i) % mod;

  ll dinv = 1;
  ll pow = mod - 2;
  ll m = d;
  while (pow) {
    if (pow & 1)
      dinv = (dinv * m) % mod;

    pow >>= 1;
    m = (m * m) % mod;
  }

  ans = (ans * dinv) % mod;
  cout << ans << nl;

  return 0;
}
