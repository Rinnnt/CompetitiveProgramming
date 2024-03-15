#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (auto &a : as) cin >> a;

    vector<vector<int>> bought(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
      if (i > 0) {
        // increase buying by 1's to buying by 2's
        ll amt = min(as[i], bought[i - 1][0]);
        bought[i - 1][0] -= amt;
        bought[i][1] += amt;
        as[i] -= amt;

        // increase buying by 2's to buying by 3's
        amt = min(as[i], bought[i - 1][1]);
        bought[i - 1][1] -= amt;
        bought[i][2] += amt;
        as[i] -= amt;

      }
      // set remainder as buying by 1's
      bought[i][0] = as[i];
    }

    ll cost = 0;
    for (int i = 0; i < n; i++) {
      cost += 3 * bought[i][0] + 5 * bought[i][1] + 7 * bought[i][2];
    }

    cout << cost << nl;

    return 0;
}
