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

      int n, q;
      cin >> n >> q;
      vector<pair<ll, pii>> szs;
      szs.push_back({0, {-1, -1}});
      bool overflow = false;
      for (int i = 0; i < n; i++) {
        int b, x;
        cin >> b >> x;
        if (overflow) continue;
        if (b == 1)
          szs.push_back({szs.back().first + 1, {1, x}});
        else {
          if ((double)(x + 1) > (double)2e18 / (double)szs.back().first)
            overflow = true;
          else
            szs.push_back({szs.back().first * (x + 1), {2, x}});
        }
      }
      szs.push_back({1e18 + 100, {-1, -1}});

      for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        int idx = lower_bound(szs.begin(), szs.end(), make_pair(k, make_pair(0, 0))) - szs.begin();
        while (!(szs[idx].first == k && szs[idx].second.first == 1)) {
          k %= szs[idx - 1].first;
          if (k == 0) k = szs[idx - 1].first;
          idx = lower_bound(szs.begin(), szs.end(), make_pair(k, make_pair(0, 0))) - szs.begin();
        }
        cout << szs[idx].second.second << " ";
      }
      cout << nl;

    }

    return 0;
}
