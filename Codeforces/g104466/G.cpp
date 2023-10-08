#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int tmp;
    cin >> n;
    tmp = n;
    int ans = 0;
    int digits = 0;
    while (tmp >= 10) {
      digits += 1;
      tmp /= 10;
    }

    int ones = 1;
    for (int i = 0; i < digits; i++) {
      ones *= 10;
      ones += 1;
    }
    if (digits == 0) {
      ans += 1;
    }

    for (int i = 1; i < 10; i++) {
      if (n >= ones * i) {
        ans += 1;
      } else {
        break;
      }
    }
    ans += digits * 10;

    cout << ans << nl;

    return 0;
}
