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

      vector<ll> cnt(n + 2, 0);
      vector<ll> pref(n + 2, 0);
      for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a + 1]++;
      }

      for (int i = 1; i < n + 2; i++)
        pref[i] = pref[i - 1] + cnt[i];

      ll ans = 0;
      for (int i = 1; i <= n + 1; i++) {
        if (cnt[i] >= 3)
          ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        if (cnt[i] >= 2)
          ans += cnt[i] * (cnt[i] - 1) * pref[i - 1] / 2;
      }

      cout << ans << nl;

    }

    return 0;
}
