#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      ll n, k, g;
      cin >> n >> k >> g;

      if (n == 1) {
        cout << 0 << '\n';
        continue;
      }

      ll r = (g - 1) / 2;
      ll a = r * n;
      if (a > k * g) {
        cout << k * g << '\n';
        continue;
      }

      ll x = ((k * g) - a + (g-1)) / g;
      ll saved = (k - x) * g;

      cout << saved << '\n';
    }

    return 0;
}
