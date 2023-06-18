#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
      int n, k, q;
      cin >> n >> k >> q;

      vector<int> temps(n, 0);
      for (int i = 0; i < n; i++) {
        cin >> temps[i];
      }

      int consec = 0;
      vector<int> consecs;
      for (int i = 0; i < n; i++) {
        if (temps[i] <= q) {
          consec++;
        } else {
          if (consec >= k) {
            consecs.push_back(consec - k + 1);
          }
          consec = 0;
        }
      }
      if (consec >= k) {
        consecs.push_back(consec - k + 1);
      }

      ll result = 0;
      for (ll x : consecs) {
        result += (x * (x + 1)) / 2;
      }

      cout << result << '\n';
    }

    return 0;
}
