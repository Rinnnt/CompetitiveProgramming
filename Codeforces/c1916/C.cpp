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

      ll n;
      cin >> n;
      vector<ll> a(n + 1);
      vector<ll> p(n + 1, 0);
      vector<ll> o(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        o[i] = o[i - 1] + (a[i] % 2);
      }

      for (int i = 1; i <= n; i++) {
        ll lose = o[i] / 3;
        lose += (i > 1 && o[i] % 3 == 1);
        cout << p[i] - lose << " ";
      }
      cout << nl;

    }

    return 0;
}
