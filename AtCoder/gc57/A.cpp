#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll left, right;
    cin >> left >> right;
    ll l = left - 1;
    ll r = right + 1;

    while (l + 1 < r) {
      ll mid = (l + r) / 2;

      ll tmp = mid;
      int digits = 0;
      while (tmp) {
        digits++;
        tmp /= 10;
      }

      ll add = 1;
      while (digits--) add *= 10;

      // if mid == 100, 1000 is next largest with it as substring
      // or mid == 110, 1100 is next largest not 1110
      //
      // otherwise if mid = 369, 1369 is next largest
      ll next = min(mid * 10, mid + add);

      if (next <= right)
        l = mid;
      else
        r = mid;
    }

    cout << right - l << nl;
  }

  return 0;
}

