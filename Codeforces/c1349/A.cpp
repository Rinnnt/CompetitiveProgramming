#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 2) {
      ll x, y;
      cin >> x >> y;
      cout << x * y / __gcd(x, y) << nl;
      return 0;
    }

    vector<pair<int, pii>> pcs(200001, {0, {1e9, 1e9}});
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int d = 2; d * d <= m; d++) {
        if (m % d == 0) {
          pcs[d].first++;
          int c = 0;
          while (m % d == 0) {
            m /= d;
            c++;
          }
          if (c < pcs[d].second.first) {
            pcs[d].second.second = pcs[d].second.first;
            pcs[d].second.first = c;
          } else if (c < pcs[d].second.second) {
            pcs[d].second.second = c;
          }
        }
      }

      if (m > 1) {
        pcs[m].first++;
        if (1 < pcs[m].second.first) {
          pcs[m].second.second = pcs[m].second.first;
          pcs[m].second.first = 1;
        } else if (1 < pcs[m].second.second) {
          pcs[m].second.second = 1;
        }
      }
    }

    ll ans = 1;
    for (int p = 0; p < 200001; p++) {
      if (pcs[p].first == n)
        for (int i = 0; i < pcs[p].second.second; i++)
          ans *= p;
      if (pcs[p].first == n - 1)
        for (int i = 0; i < pcs[p].second.first; i++)
          ans *= p;
    }

    cout << ans << nl;

    return 0;
}
