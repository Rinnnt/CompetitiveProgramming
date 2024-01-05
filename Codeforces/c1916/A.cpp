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

      int n, k;
      cin >> n >> k;
      ll prod = 1LL;
      for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        prod *= b;
      }

      if (2023LL % prod) {
        cout << "NO" << nl;
      } else {
        cout << "YES" << nl;
        int div = 2023LL / prod;
        for (int i = 0; i < k - 1; i++) {
          cout << "1 ";
        }
        cout << div << nl;
      }

    }

    return 0;
}
