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

      vector<int> a(n);
      int ns = 0;
      bool zero = false;
      for (auto &x : a) {
        cin >> x;
        if (x < 0) ns++;
        if (x == 0) zero = true;
      }

      if (zero) {
        cout << 0 << nl;
        continue;
      }

      if (ns % 2) {
        cout << 0 << nl;
        continue;
      }

      cout << 1 << nl;
      cout << "1 0" << nl;
    }

    return 0;
}
