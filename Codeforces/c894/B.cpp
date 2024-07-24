#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll mod = 1e9 + 7;

ll binpow(ll n, ll m) {
  ll res = 1;
  while (m) {
    if (m % 2) res = res * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    if (k == -1 && (n + m) % 2) {
      cout << 0 << nl;
    } else {
      cout << binpow(binpow(2LL, n - 1), m - 1) << nl;
    }

    return 0;
}
