#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define nl '\n'

ll modpow(ull n, ull m, ull mod) {
  ull ans = 1;
  n %= mod;
  while (m) {
    if (m % 2) ans = ans * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ans;
}

bool check_composite(ull n, ull a, ull d, int s) {
  ll x = modpow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; r++) {
    x = x * x % n;
    if (x == n - 1) return false;
  }
  return true;
}

bool MillerRabin(ull n) {
  if (n < 2) return false;

  int r = 0;
  ull d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }
  for (int a : {2, 3, 4, 5, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    ll cnt = 0;
    while (t--) {
      ull area;
      cin >> area;
      if (MillerRabin(2 * area + 1)) cnt++;
    }

    cout << cnt << nl;

    return 0;
}
