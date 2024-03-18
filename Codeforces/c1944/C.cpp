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
      vector<int> cnt(n, 0);
      for (auto &a : as) {
        cin >> a;
        cnt[a]++;
      }

      bool singleUsed = false;
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (cnt[i] >= 2) ans++;
        else if (cnt[i] == 1 && !singleUsed) {
          ans++;
          singleUsed = true;
        }
        else if (cnt[i] == 1 && singleUsed) break;
        else break;
      }

      cout << ans << nl;
    }

    return 0;
}
