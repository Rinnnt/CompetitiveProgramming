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
      vector<int> ps(2 * n);
      vector<int> pms(2 * n + 1, 0);
      for (int i = 0; i < 2 * n; i++) {
        cin >> ps[i];
        pms[i + 1] = max(pms[i], ps[i]);
      }

      int g = 0;
      vector<int> gs;
      for (int i = 1; i <= 2 * n; i++) {
        g++;
        if (i == 2 * n || pms[i + 1] != pms[i]) {
          gs.push_back(g);
          g = 0;
        }
      }

      vector<bool> dp(n + 1, false);
      dp[0] = true;
      for (int i = 0; i < gs.size(); i++) {
        for (int j = n; j >= gs[i]; j--) {
          dp[j] = dp[j] | dp[j - gs[i]];
        }
      }

      cout << (dp[n] ? "YES" : "NO") << nl;

    }

    return 0;
}
