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

      vector<ll> xs(n);
      set<ll> xset;
      for (auto &x : xs) {
        cin >> x;
        xset.insert(x);
      }
      int y;
      for (int i = 0; i < n; i++) cin >> y;

      sort(xs.begin(), xs.end());

      vector<int> ls(n), rs(n);

      int l = 0;
      for (int r = 0; r < n; r++) {
        while (xs[r] - xs[l] > k) l++;
        ls[r] = r - l + 1;
        if (r > 0) ls[r] = max(ls[r], ls[r - 1]);
      }

      int r = n - 1;
      for (int l = n - 1; l >= 0; l--) {
        while (xs[r] - xs[l] > k) r--;
        rs[l] = r - l + 1;
        if (l < n - 1) rs[l] = max(rs[l], rs[l + 1]);
      }

      int ans = 1;
      for (int i = 0; i < n - 1; i++) {
        ans = max(ans, ls[i] + rs[i + 1]);
      }
      cout << ans << nl;

    }

    return 0;
}
