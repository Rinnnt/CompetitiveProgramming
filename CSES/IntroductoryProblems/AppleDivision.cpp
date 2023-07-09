#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      total += a[i];
    }
    ll sum = 0;
    for (int i = 0; i < 1 << n; i++) {
      ll cs = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          cs += a[j];
        }
      }
      if (cs <= total / 2) {
        sum = max(cs, sum);
      }
    }
    cout << total - 2 * sum << nl;

    return 0;
}