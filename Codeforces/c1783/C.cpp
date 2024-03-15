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

      int n, m;
      cin >> n >> m;
      vector<int> as(n);
      for (auto &a : as) cin >> a;

      vector<int> bs = as;
      sort(bs.begin(), bs.end());

      int ans = 0;
      for (int i = 0; i < n && bs[i] <= m; i++) {
        m -= bs[i];
        ans++;
      }
      if (ans != 0 && ans != n && m + bs[ans - 1] >= as[ans]) ++ans;
      cout << n - ans + 1 << nl;

    }

    return 0;
}
