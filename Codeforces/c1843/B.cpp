#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n;
      cin >> n;
      vector<ll> a(n);
      ll sum = 0;
      for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
      }

      ll ops = 0;
      bool neg = false;
      for (int i = 0; i < n; i++) {
        if (a[i] < 0 && !neg) {
          ops++;
        }
        if (a[i] < 0) {
          neg = true;
        }
        if (a[i] > 0) {
          neg = false;
        }
      }

      cout << sum << " " << ops << nl;
    }

    return 0;
}
