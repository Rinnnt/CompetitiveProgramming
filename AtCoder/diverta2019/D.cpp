#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n;
  cin >> n;

  ll i = 1;
  ll ans = 0;
  while (n > i * (i + 1)) {
    ll m = (n / i) - 1;
    if (n / m == n % m)
      ans += m;
    i++;
  }

  cout << ans << nl;

  return 0;
}

