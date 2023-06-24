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
      ll q;
      cin >> q;

      ll l, r;
      l = 1, r = 1e18;
      while (q--) {

        ll m, a, b, n;
        cin >> m >> a >> b;

        if (m == 1) {
          cin >> n;
          ll newl, newr;
          newl = a + (n - 2) * (a - b) + 1;
          newr = a + (n - 1) * (a - b);
          if (n == 1) {
            newl = 1;
            newr = a;
          }
          if (newl > r || newr < l) {
            cout << "0 ";
          } else {
            cout << "1 ";
            l = max(l, newl);
            r = min(r, newr);
            //cout << "NEWL: " << l << nl;
            //cout << "NEWR: " << r << nl;
          }
        } else {
          ll lb, ub;
          lb = max(1LL, (((l - a) + (a - b - 1)) / (a - b)) + 1);
          ub = max(1LL, (((r - a) + (a - b - 1)) / (a - b)) + 1);
          //cout << "LOWERB: " << lb << nl;
          //cout << "UPPERB: " << ub << nl;
          if (lb == ub) {
            cout << lb << " ";
          } else {
            cout << "-1 ";
          }
        }
      }
      cout << nl;
    }

    return 0;
}
