#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

ll find(ll x) {
  ll l = -1, r = 1e5;

  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (mid * (mid - 1) / 2 <= x)
      l = mid;
    else
      r = mid;
  }

  return l;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll a, b, c, d, zs, os;
  cin >> a >> b >> c >> d;

  if (a == 0) {
    os = find(d);
    if (os * (os - 1) / 2 != d) {
      cout << "impossible" << nl;
      return 0;
    }

    if (b == 0 && c == 0) {
      cout << string(os, '1') << nl;
      return 0;
    } else {
      if (b + c != os) {
        cout << "impossible" << nl;
        return 0;
      }
      cout << string(c, '1') << "0" << string(b, '1') << nl;
      return 0;
    }
  }

  if (d == 0) {
    zs = find(a);
    if (zs * (zs - 1) / 2 != a) {
      cout << "impossible" << nl;
      return 0;
    }

    if (b == 0 && c == 0) {
      cout << string(zs, '0') << nl;
      return 0;
    } else {
      if (b + c != zs) {
        cout << "impossible" << nl;
        return 0;
      }
      cout << string(b, '0') << "1" << string(c, '0') << nl;
      return 0;
    }
  }

  zs = find(a);
  os = find(d);

  if (zs * (zs - 1) / 2 != a) {
    cout << "impossible" << nl;
    return 0;
  }

  if (os * (os - 1) / 2 != d) {
    cout << "impossible" << nl;
    return 0;
  }

  ll tot = zs * os;
  if (b + c != tot) {
    cout << "impossible" << nl;
    return 0;
  }

  string res;

  ll prefos = c / zs;
  ll remos = c % zs;
  if (prefos == os) {
    res += string(os, '1');
    res += string(zs, '0');
  } else {
    res += string(prefos, '1');
    res += string(zs - remos, '0');
    res += "1";
    res += string(remos, '0');
    res += string(os - prefos - 1, '1');
  }

  cout << res << nl;

  return 0;
}

