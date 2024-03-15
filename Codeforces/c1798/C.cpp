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
      vector<ll> as(n);
      vector<ll> bs(n);
      ll cgcd = 1;
      ll clcm = 2;
      int ans = 0;
      for (int i = 0; i < n; i++) {
        cin >> as[i] >> bs[i];
        ll ngcd = __gcd(cgcd, as[i] * bs[i]);
        ll nlcm = (clcm * bs[i]) / __gcd(clcm, bs[i]);
        if (ngcd % nlcm != 0) {
          ans++;
          cgcd = as[i] * bs[i];
          clcm = bs[i];
        } else {
          cgcd = ngcd;
          clcm = nlcm;
        }
      }

      cout << ans << nl;

    }

    return 0;
}
