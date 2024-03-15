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
      vector<ll> bs(n);
      for (auto &b : bs) cin >> b;

      vector<ll> lmax(n);
      lmax[0] = -1e9;
      for (int i = 1; i < n; i++)
        lmax[i] = max(lmax[i - 1], bs[i - 1] - (n - i));

      vector<ll> rmax(n);
      rmax[n - 1] = -1e9;
      for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(rmax[i + 1], bs[i + 1] - i);

      ll ans = 0;
      for (int i = 1; i < n - 1; i++)
        ans = max(ans, bs[i] + lmax[i] + (n - i - 1) + rmax[i] + (i - 1));

      cout << ans << nl;
    }

    return 0;
}
