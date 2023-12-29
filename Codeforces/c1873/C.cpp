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

      int ans = 0;
      for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
          if (s[j] == 'X')
            ans += 5 - max(max(4 - j, j - 5), max(4 - i, i - 5));
      }

      cout << ans << nl;

    }

    return 0;
}
