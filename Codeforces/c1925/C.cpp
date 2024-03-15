#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int nxts[1001][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j < 26; j++) {
          nxts[i][j] = 1e9;
        }
      }

      int n, k, m;
      cin >> n >> k >> m;
      string s;
      cin >> s;

      for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
          nxts[i][j] = nxts[i + 1][j];
        }
        nxts[i][s[i] - 'a'] = i;
      }

      int idx = 0;
      string ans = "";
      while (n--) {
        if (idx >= m) {
          ans += 'a';
          idx = 1e9 + 1;
        } else {
          int nxt = idx - 1;
          char nxtc;
          for (int j = 0; j < k; j++) {
            if (nxts[idx][j] + 1 > nxt) {
              nxt = nxts[idx][j] + 1;
              nxtc = 'a' + j;
            }
          }
          idx = nxt;
          ans += nxtc;
        }
      }

      if (idx == 1e9 + 1) {
        cout << "NO" << nl;
        cout << ans << nl;
      } else {
        cout << "YES" << nl;
      }

    }

    return 0;
}
