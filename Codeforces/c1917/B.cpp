#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

bool seen[26] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i < 26; i++)
        seen[i] = false;

      ll n;
      cin >> n;

      string s;
      cin >> s;

      ll ans = 0;
      for (int i = 0; i < n; i++) {
        if (!seen[s[i] - 'a']) {
          ans += n - i;
          seen[s[i] - 'a'] = true;
        }
      }

      cout << ans << nl;

    }

    return 0;
}
