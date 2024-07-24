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
      string revs = s;
      reverse(revs.begin(), revs.end());

      vector<int> factors;
      for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
          factors.push_back(i);
          if (n / i != i)
            factors.push_back(n / i);
        }
      }

      sort(factors.begin(), factors.end());

      int res = 0;
      for (auto f : factors) {
        bool possible = true;
        int wrong = 0;
        for (int i = 0; i < n; i++) {
          if (i >= f && s[i] != s[i % f]) {
            wrong++;
            if (wrong > 1) {
              possible = false;
              break;
            }
          }
        }

        if (possible) {
          res = f;
          break;
        }

        possible = true;
        wrong = 0;
        for (int i = 0; i < n; i++) {
          if (i >= f && revs[i] != revs[i % f]) {
            wrong++;
            if (wrong > 1) {
              possible = false;
              break;
            }
          }
        }

        if (possible) {
          res = f;
          break;
        }

      }

      cout << res << nl;

    }

    return 0;
}
