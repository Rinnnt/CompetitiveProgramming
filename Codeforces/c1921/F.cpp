#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const ll block_size = 300;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      int n, q;
      cin >> n >> q;
      vector<ll> as(n);
      for (auto &a : as) cin >> a;

      vector<vector<ll>> ss(block_size + 1, vector<ll>(n, 0));
      vector<vector<ll>> ps(block_size + 1, vector<ll>(n, 0));
      for (int k = 1; k <= block_size; k++) {
        for (int i = 0; i < n; i++) {
          ss[k][i] = (i - k >= 0 ? ss[k][i - k] : 0LL) + as[i];
          ps[k][i] = (i - k >= 0 ? ps[k][i - k] : 0LL) + as[i] * ((i / k) + 1);
        }
      }

      while (q--) {
        ll s, d, k;
        cin >> s >> d >> k;
        s--;
        if (d > block_size) {
          ll res = 0;
          for (int i = 1; i <= k; i++) {
            res += as[s + (i - 1) * d] * i;
          }
          cout << res << " ";
        } else {
          ll res = ps[d][s + (k - 1) * d];
          if (s - d >= 0) {
            res -= ps[d][s - d];
            res -= (ss[d][s + (k - 1) * d] - ss[d][s - d]) * ((s - d) / d + 1);
          }
          cout << res << " ";
        }
      }

      cout << nl;
    }


    return 0;
}
