#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll a, b;
  cin >> a >> b;

  ll cnt = 0;
  while (a && b) {
    ll g = __gcd(a, b);
    a /= g;
    b /= g;

    ll d = abs(a - b);
    if (d == 0) {
      cnt += 1;
      break;
    }

    if (d == 1) {
      cnt += min(a, b);
      break;
    }

    ll v = min(a, b);
    for (ll i = 1; i * i <= d; i++) {
      if (d % i == 0) {
        if (i > 1) {
          v = min(v, a % i);
        }
        v = min(v, a % (d / i));
      }
    }

    a -= v;
    b -= v;
    cnt += v;
  }

  cout << cnt << nl;

  return 0;
}

