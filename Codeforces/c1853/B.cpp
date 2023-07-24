#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll memo[100];

ll fib(int k) {
  if (k == 0) {
    return 0;
  }
  if (k == 1) {
    return 1;
  }
  if (memo[k]) {
    return memo[k];
  }
  return memo[k] = fib(k - 1) + fib(k - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n, k;
      cin >> n >> k;
      int ans;
      if (k > 30) {
        ans = n == 0 ? 1 : 0;
      } else {
        int l, r;
        if (k % 2) {
          l = (fib(k - 1) * n + fib(k) - 1) / fib(k);
          r = fib(k - 2) * n / fib(k - 1);
        } else {
          r = fib(k - 1) * n / fib(k);
          l = (fib(k - 2) * n + fib(k - 1) - 1) / fib(k - 1);
        }
        ans = r - l + 1;
      }
      cout << ans << nl;
    }

    return 0;
}
