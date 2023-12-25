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

  int n;
  cin >> n;

  ll a = 1;
  ll b = 1;

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;

    ll ta = a + (x - (a % x)) % x;
    ll tb = y * (ta / x);

    ll ttb = b + (y - (b % y)) % y;
    ll tta = x * (ttb / y);

    if (tb < b) {
      a = tta;
      b = ttb;
    } else if (tta < a) {
      a = ta;
      b = tb;
    } else {
      if (ta + tb < tta + ttb) {
        a = ta;
        b = tb;
      } else {
        a = tta;
        b = ttb;
      }
    }
  }

  cout << a + b << nl;

  return 0;
}

