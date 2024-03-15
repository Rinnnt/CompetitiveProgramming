#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pll> ps(n);
    for (auto &p : ps) cin >> p.second;
    for (auto &p : ps) cin >> p.first;

    sort(ps.begin(), ps.end());

    ll ans = 0;
    ll maxb = 0;
    ll samebmax = 0;
    pll prevp = {0LL, 0LL};
    for (auto p : ps) {
      if (p.first != prevp.first)
        maxb = samebmax;
      ll extends = (max(max(maxb, p.first) - p.second, 0LL) + 29) / 30;
      samebmax = max(samebmax, p.second + 30 * extends);
      ans += extends;
      prevp = p;
    }

    cout << ans << nl;

    return 0;
}
