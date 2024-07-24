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
      if (a < b && b < c) {
        cout << "STAIR" << nl;
      } else if (a < b && b > c) {
        cout << "PEAK" << nl;
      } else {
        cout << "NONE" << nl;
      }

    }

    return 0;
}
