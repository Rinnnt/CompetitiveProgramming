#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int cnt[26] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      for (int i = 0; i < 26; i++)
        cnt[i] = 0;

      int n;
      cin >> n;
      string s;
      cin >> s;
      for (auto c : s) {
        cnt[c - 'A']++;
      }

      int ans = 0;
      for (int i = 0 ; i < 26; i++) {
        if (cnt[i] > i) {
          ans++;
        }
      }

      cout << ans << nl;

    }

    return 0;
}
