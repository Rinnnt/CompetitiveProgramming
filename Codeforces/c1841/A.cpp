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
      if (n >= 5) {
        cout << "Alice" << nl;
      } else {
        cout << "Bob" << nl;
      }
    }

    return 0;
}
