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
      string s;
      cin >> s;

      int ans = 0;
      for (int l = 0; l < n; l++) {
        int adjms = 0;
        int mcnt = 0;
        int pcnt = 0;
        for (int r = l; r < n; r++) {
          if (s[r] == '+') {
            pcnt++;
          } else {
            mcnt++;
          }

          if (mcnt >= pcnt && (mcnt - pcnt) % 3 == 0) ans++;
        }
      }

      cout << ans << nl;

    }

    return 0;
}
