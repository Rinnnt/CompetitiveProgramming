#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n;
int as[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      cin >> n;
      for (int i = 0; i < n; i++)
        cin >> as[i];

      int ans = 0;
      for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
          int g = 0;
          for (int i = 0; i + k < n; i++)
            g = __gcd(g, abs(as[i + k] - as[i]));
          ans += (g != 1);
        }
      }

      cout << ans << nl;
    }

    return 0;
}
