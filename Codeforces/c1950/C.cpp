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

      string s;
      cin >> s;

      int h = stoi(s.substr(0, 2));
      int m = stoi(s.substr(3, 2));

      bool am = true;
      if (h >= 12) {
        am = false;
        if (h > 12)
          h -= 12;
      }
      if (h == 0)
        h += 12;

      cout << setfill('0') << setw(2) << h;
      cout << ':';
      cout << setfill('0') << setw(2) << m;
      cout << (am ? " AM" : " PM") << nl;


    }

    return 0;
}
