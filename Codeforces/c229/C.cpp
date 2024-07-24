#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> deg(n + 1, 0);
    for (ll i = 0; i < m; i++) {
      ll a, b;
      cin >> a >> b;
      deg[a]++;
      deg[b]++;
    }

    // assign:
    // +2 to pair of (edge, edge)
    // -1 to pair of (edge, antiedge)
    // +2 to pair of (antiedge, antiedge)
    //
    // sum of single node:
    // 2 * (choose 2 from degree)
    // -1 * (choose 1 from deg, choose 1 from n - deg)
    // 2 * (choose 2 from (n - deg))
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
      ll d = deg[i];
      res += d * (d - 1) - d * (n - d - 1) + (n - d - 1) * (n - d - 2);
    }

    cout << res / 6 << nl;

    return 0;
}
