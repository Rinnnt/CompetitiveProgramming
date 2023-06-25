#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      ll n, m;
      cin >> n >> m;

      ll a, b;
      a = 0;
      b = 0;
      for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a += x;
      }
      for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b += x;
      }

      if (a > b) {
        cout << "Tsondu";
      } else if (a < b) {
        cout << "Tenzing";
      } else {
        cout << "Draw";
      }
      cout << nl;

    }

    return 0;
}
