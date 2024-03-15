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

      int n;
      cin >> n;
      int lo = 0;
      int hi = 1e9 + 1;
      vector<int> ns;
      for (int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
          lo = max(lo, x);
        } else if (a == 2) {
          hi = min(hi, x);
        } else {
          ns.push_back(x);
        }
      }

      int cant = 0;
      for (auto n : ns)
        if (n >= lo && n <= hi)
          cant++;
      int ans = max(hi - lo + 1, 0) - cant;

      cout << ans << nl;
    }

    return 0;
}
