#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;

      ll one = 0;
      ll biggest = 0;
      ll two = 0;
      for (ll i = 0; i < n ; i++) {
        ll x;
        cin >> x;
        if (x == 1) {
          one = i + 1;
        }
        if (x == n) {
          biggest = i + 1;
        }
        if (x == 2) {
          two = i + 1;
        }
      }

      if ((one < biggest && biggest < two) || (two < biggest && biggest < one)) {
        cout << "1 1" << '\n';
      } else {
        if ((biggest < one && one < two) || (two < one && one < biggest)) {
          cout << one <<  " " << biggest << '\n';
        } else {
          cout << two << " " << biggest << '\n';
        }
      }
    }

    return 0;
}
