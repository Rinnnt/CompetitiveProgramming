#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) {
    cout << 10000 + a * 1000 << nl;
  } else if (a != b && a != c && b != c) {
    cout << max(a, max(b, c)) * 100 << nl;
  } else {
    if (a == b) {
      cout << 1000 + a * 100 << nl;
    } else if (a == c) {
      cout << 1000 + a * 100 << nl;
    } else {
      cout << 1000 + b * 100 <<nl;
    }
  }

  return 0;
}
