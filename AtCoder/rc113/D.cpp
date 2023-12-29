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
    if (m % 2) ans = (ans * n) % mod;
    n = (n * n) % mod;
    m >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;

  if (n == 1) {
    cout << modpow(k, m) << nl;
    return 0;
  }

  if (m == 1) {
    cout << modpow(k, n) << nl;
    return 0;
  }

  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = (ans + (((modpow(i, n) - modpow(i - 1, n)) % mod) * (modpow(k - i + 1, m))) % mod) % mod;
  }
  cout << (ans + mod) % mod << nl;

  return 0;
}

