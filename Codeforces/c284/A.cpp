#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int p;
    cin >> p;

    int ans = 0;
    for (int i = 1; i < p; i++) {
      bool prim = true;
      int x = i;
      for (int j = 0; j < p - 2; j++) {
        if (x - 1 == 0) {
          prim = false;
          break;
        }
        x = x * i % p;
      }
      if (prim && x - 1 == 0) ans++;
    }

    cout << ans << nl;

    return 0;
}
