#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      int prev, curr;
      cin >> prev;
      int ans = 1e9;
      for (int i = 0; i < n - 1; i++) {
        cin >> curr;
        ans = min(ans, max(0, curr - prev + 1));
        prev = curr;
      }

      cout << (ans + 1) / 2 << nl;

    }

    return 0;
}
