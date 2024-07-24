#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> as(4);
    for (auto &a : as) cin >> a;

    vector<int> ds(3);
    for (int i = 0; i < 3; i++)
      ds[i] = as[i + 1] - as[i];

    if (ds[0] == ds[1] && ds[1] == ds[2])
      cout << as[3] + ds[0] << nl;
    else {
      if (as[1] * as[1] == as[0] * as[2] && as[2] * as[2] == as[1] * as[3] && (as[3] * as[3]) % as[2] == 0) {
        cout << as[3] * as[3] / as[2] << nl;
      } else {
        cout << 42 << nl;
      }
    }

    return 0;
}
