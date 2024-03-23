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

      ll mp = 0;
      ll mpl = 0;
      ll mph = 0;
      for (auto x : xset) {
        if (upper_bound(xs.begin(), xs.end(), x + k) - lower_bound(xs.begin(), xs.end(), x) > mp) {
          mp = upper_bound(xs.begin(), xs.end(), x + k) - lower_bound(xs.begin(), xs.end(), x);
          mpl = x;
          mph = x + k;
        }
        if (upper_bound(xs.begin(), xs.end(), x) - lower_bound(xs.begin(), xs.end(), x - k) > mp) {
          mp = upper_bound(xs.begin(), xs.end(), x) - lower_bound(xs.begin(), xs.end(), x - k);
          mpl = x - k;
          mph = x;
        }
      }

      ll mp2 = 0;
      for (auto x : xset) {
        if (x > mph || x + k < mpl) {
          if (upper_bound(xs.begin(), xs.end(), x + k) - lower_bound(xs.begin(), xs.end(), x) > mp2) {
            mp2 = upper_bound(xs.begin(), xs.end(), x + k) - lower_bound(xs.begin(), xs.end(), x);
          }
        }
        if (x - k > mph || x < mpl) {
          if (upper_bound(xs.begin(), xs.end(), x) - lower_bound(xs.begin(), xs.end(), x - k) > mp2) {
            mp2 = upper_bound(xs.begin(), xs.end(), x) - lower_bound(xs.begin(), xs.end(), x - k);
          }
        }
      }

      cout << mp + mp2 << nl;

    }

    return 0;
}
