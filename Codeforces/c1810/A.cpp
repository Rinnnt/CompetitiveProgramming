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

      bool possible = false;
      vector<int> as(n + 1, 0);
      for (int i = 1; i < n + 1; i++) {
        cin >> as[i];
        if (as[i] <= i) {
          possible = true;
        }
      }

      if (possible) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }

    }

    return 0;
}
