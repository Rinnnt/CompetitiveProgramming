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

      int idx = 1;
      while (s[idx] == '0') idx++;

      if (idx == s.size()) {
        cout << -1 << nl;
        continue;
      }

      string a = s.substr(0, idx);
      string b = s.substr(idx, s.size() - idx);

      int av = stoi(a);
      int bv = stoi(b);

      if (av < bv) {
        cout << av << " " << bv << nl;
      } else {
        cout << -1 << nl;
      }

    }

    return 0;
}
