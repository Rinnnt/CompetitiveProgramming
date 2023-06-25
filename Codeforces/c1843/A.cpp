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

      vector<ll> a(n, 0);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }

      sort(a.begin(), a.end());

      ll cost = 0;
      for (int i = 0; i < n / 2; i++) {
        cost += a[n - i - 1] - a[i];
      }

      cout << cost << nl;
    }

    return 0;
}
