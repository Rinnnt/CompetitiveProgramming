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
      string s;
      cin >> s;

      ll ans = 0;
      for (auto x : s)
        ans += (x == '+' ? 1 : -1);

      cout << abs(ans) << nl;

    }

    return 0;
}
