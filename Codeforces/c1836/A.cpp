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

      vector<int> p(100, 0);
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x]++;
      }

      bool possible = true;
      for (int i = 1; i < 100; i++) {
        if (p[i] > p[i - 1]) {
          possible = false;
          break;
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
