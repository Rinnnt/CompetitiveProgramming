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
      ll n;
      cin >> n;

      ll first;
      cin >> first;

      string result = "1";

      ll x;
      ll prev = first;
      bool shifted = false;
      for (int i = 1; i < n; i++) {
        cin >> x;
        if (!shifted) {
          if (x >= prev) {
            result += "1";
            prev = x;
          } else if (x <= first) {
            shifted = true;
            result += "1";
            prev = x;
          } else {
            result += "0";
          }
        } else {
          if (x <= first && x >= prev) {
            result += "1";
            prev = x;
          } else {
            result += "0";
          }
        }
      }

      cout << result << nl;
    }

    return 0;
}
