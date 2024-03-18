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

      int n;
      cin >> n;

      string a, b, c;
      cin >> a >> b >> c;

      bool possible = false;
      for (int i = 0; i < n; i++) {
        if (a[i] != c[i] && b[i] != c[i]) possible = true;
      }

      cout << (possible ? "YES" : "NO") << nl;

    }

    return 0;
}
