#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, v;
    cin >> n >> v;
    vector<int> as(n);
    for (auto &a : as) cin >> a;
    vector<int> bs(n);
    for (auto &b : bs) cin >> b;

    ld maxm = 200;
    for (int i = 0; i < n; i++) {
      maxm = min(maxm, ((ld)bs[i]) / as[i]);
    }

    ld l = 0;
    ld r = maxm;
    while (l + 0.0000001 < r) {
      ld mid = (l + r) / 2;
      ld res = 0;
      for (auto a : as) res += a * mid;
      if (res > v) {
        r = mid;
      } else {
        l = mid;
      }
    }

    ld res = 0;
    for (auto a : as) res += a * l;

    cout << fixed << setprecision(15) << res << nl;

    return 0;
}
