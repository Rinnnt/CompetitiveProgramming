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

      int n, c;
      cin >> n >> c;

      vector<int> as(n);
      vector<int> cnt(c + 1, 0);
      vector<int> pref(c + 1, 0);
      for (auto &a : as) {
        cin >> a;
        cnt[a]++;
      }

      for (int i = 1; i < c + 1; i++)
        pref[i] = pref[i - 1] + cnt[i];

      bool integral = true;
      for (int r = 1; r <= c; r++) {
        if (cnt[r] != 0) continue;
        for (int y = 1; r * y <= c; y++) {
          if (cnt[y] == 0) continue;
          if (pref[min(c, y * (r + 1) - 1)] != pref[y * r - 1]) {
            integral = false;
            break;
          }
        }
        if (!integral) break;
      }

      cout << (integral ? "Yes" : "No") << nl;
    }

    return 0;
}
