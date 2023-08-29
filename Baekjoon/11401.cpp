#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll mod = 1e9 + 7;

ll fact[4000000];

int modpow(int x, int p) {
  if (p == 1) {
    return x;
  }

  ll m = modpow(x, p / 2);
  ll m2 = (m * m) % mod;
  if (p % 2) {
    return (m2 * x) % mod;
  } else {
    return m2;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }

  cout << (((fact[n] * modpow(fact[k], mod - 2)) % mod) * modpow(fact[n - k], mod - 2)) % mod;
}
