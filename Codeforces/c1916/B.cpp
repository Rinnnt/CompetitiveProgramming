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

      ll a, b;
      cin >> a >> b;

      ll l = (a * b) / __gcd(a, b);
      if (l == b) {
        l *= (b / a);
      }

      cout << l << nl;

    }

    return 0;
}
