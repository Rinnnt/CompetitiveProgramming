#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
      int n;
      string s;
      cin >> n >> s;

      string res = "";
      res += s[0];

      int idx = 1;
      char c = s[0];
      while (idx < n) {
        while (s[idx++] != c);

        if (idx >= n) {
          break;
        }

        c = s[idx++];
        res += c;
      }

      cout << res << '\n';
    }

    return 0;
}
