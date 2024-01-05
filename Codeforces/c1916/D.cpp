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

      ll n;
      cin >> n;

      if (n == 1) {
        cout << 1 << nl;
        continue;
      }

      for (int i = 0; i < n / 2; i++) {
        string sq(n, '0');
        sq[0] = '1';
        sq[i + 1] = '6';
        sq[2 * i + 2] = '9';
        cout << sq << nl;
      }
      cout << "196" << string(n - 3, '0') << nl;
      for (int i = 0; i < n / 2; i++) {
        string sq(n, '0');
        sq[0] = '9';
        sq[i + 1] = '6';
        sq[2 * i + 2] = '1';
        cout << sq << nl;
      }
    }

    return 0;
}
