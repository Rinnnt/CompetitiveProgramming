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
      int n;
      cin >> n;
      string s;
      cin >> s;

      vector<char> ans(2 * n);
      int idx = 0;
      int i = n - 1;
      while (i >= 0) {
        if (s[i] == 'a' || s[i] == 'e') {
          ans[idx++] = s[i];
          ans[idx++] = s[i - 1];
          ans[idx++] = '.';
          i -= 2;
        } else {
          ans[idx++] = s[i];
          ans[idx++] = s[i - 1];
          ans[idx++] = s[i - 2];
          ans[idx++] = '.';
          i -= 3;
        }
      }

      for (int i = idx - 2; i >= 0; i--) {
        cout << ans[i];
      }

      cout << nl;

    }

    return 0;
}
