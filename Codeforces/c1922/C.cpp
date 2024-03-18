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

      vector<int> as(n + 2);
      as[0] = 0;
      as[n + 1] = 1e9;
      for (int i = 1; i <= n; i++) cin >> as[i];

      vector<int> rdist(n + 2);
      for (int i = 1; i < n + 2; i++) rdist[i] = as[i] - as[i - 1];

      vector<int> ldist(n + 2);
      for (int i = n; i >= 0; i--) ldist[i] = as[i + 1] - as[i];

      rdist[2] = 1;
      ldist[n - 1] = 1;
      for (int i = 2; i < n; i++) {
        if (as[i + 1] - as[i] < as[i] - as[i - 1]) {
          rdist[i + 1] = 1;
        } else {
          ldist[i - 1] = 1;
        }
      }

      vector<int> rpref(n + 2, 0);
      for (int i = 1; i < n + 2; i++) rpref[i] = rpref[i - 1] + rdist[i];

      vector<int> lpref(n + 2, 0);
      for (int i = n; i >= 0; i--) lpref[i] = lpref[i + 1] + ldist[i];

      int m;
      cin >> m;

      while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
          cout << lpref[y] - lpref[x] << nl;
        } else {
          cout << rpref[y] - rpref[x] << nl;
        }
      }

    }

    return 0;
}
