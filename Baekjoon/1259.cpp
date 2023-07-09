#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  while (s != "0") {
    bool p = true;
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - i - 1]) {
        p = false;
        break;
      }
    }
    if (p) {
      cout << "yes" << nl;
    } else {
      cout << "no" << nl;
    }
    cin >> s;
  }

}
