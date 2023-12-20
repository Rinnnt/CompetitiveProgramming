#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      string s;
      cin >> s;

      int z = 0;
      int o = 0;
      for (auto c : s) {
        if (c == '1') o++;
        else z++;
      }

      int idx = 0;
      while (idx < s.size()) {
        if (s[idx] == '1') {
          if (z == 0) {
            break;
          }
          z--;
        } else {
          if (o == 0) {
            break;
          }
          o--;
        }
        idx++;
      }

      cout << s.size() - idx << nl;

    }

    return 0;
}
