#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll d = 1;
    ll abc = 0;
    for (int i = 0; i < n; i++) {
      ll nabc = (2 * abc + d) % mod;
      ll nd = 3 * abc % mod;
      d = nd;
      abc = nabc;
    }

    cout << d << nl;

    return 0;
}
