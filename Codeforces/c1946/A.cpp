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
      vector<int> as(n);
      for (auto &a : as) cin >> a;
      sort(as.begin(), as.end());

      int k = (n - 1) / 2;

      int ans = 1;
      for (int i = k + 1; i < n; i++) {
        if (as[i] == as[i - 1]) {
          ans++;
        } else {
          break;
        }
      }

      cout << ans << nl;

    }

    return 0;
}
