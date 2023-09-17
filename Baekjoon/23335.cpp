#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;

      if (n == 1) {
        cout << "deficient" << nl;
        continue;
      }

      int sum = 1;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          sum += i;
          if (i * i != n) {
            sum += n / i;
          }
        }
      }

      if (sum > n) {
        cout << "abundant" << nl;
      } else if (sum == n) {
        cout << "perfect" << nl;
      } else {
        cout << "deficient" << nl;
      }
    }

    return 0;
}
