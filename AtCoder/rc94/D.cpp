#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

vector<ll> prime_factors(ll x) {
  vector<ll> factors;
  for (ll i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      factors.push_back(i);
      x /= i;
    }
  }
  if (x != 1)
    factors.push_back(x);
  return factors;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;

    map<ll, int> factors;
    for (auto d : prime_factors(a)) {
      cout << d <<  " ";
      factors[d]++;
    }
    cout << nl;
    for (auto d : prime_factors(b)) {
      cout << d << " ";
      factors[d]++;
    }
    cout << nl;

    ll ans = 1;
    for (auto x : factors)
      ans *= x.second + 1;

    cout << (ans + 1) / 2 - 1 << nl;

  }

  return 0;
}

