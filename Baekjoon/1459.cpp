#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll x, y, w, s;
  cin >> x >> y >> w >> s;
  int odd_parity = (x + y) % 2;
  if (s <= w) {
    if (odd_parity)
      cout << s * (max(x, y) - 1) + w << nl;
    else
      cout << s * max(x, y) << nl;
  } else {
    if (2 * w <= s)
      cout << w * (x + y) << nl;
    else
      cout << s * min(x, y) + w * (max(x, y) - min(x, y)) << nl;
  }

  return 0;
}
