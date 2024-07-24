#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int a, b, c;
      cin >> a >> b >> c;
      if (a + 1 != c) {
        cout << -1 << nl;
      } else {
        int h;
        if (a == 0) {
          h = b - 1;
        } else {
          h = floor(log2(a));
          int d = a + 1;
          int r = (1 << (h + 1)) - a - 1;
          h += (max(0, b - r) + d - 1) / d;
        }
        cout << h + 1 << nl;
      }

    }

    return 0;
}
