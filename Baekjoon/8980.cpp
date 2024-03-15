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

    int n, c, m;
    cin >> n >> c >> m;

    vector<pair<pii, int>> ts(m);
    for (auto &t : ts) cin >> t.first.second >> t.first.first >> t.second;

    sort(ts.begin(), ts.end());

    vector<int> cs(n + 1, c);

    int ans = 0;
    for (auto t : ts) {
      int maxw = t.second;
      for (int i = t.first.second; i < t.first.first; i++) maxw = min(maxw, cs[i]);
      for (int i = t.first.second; i < t.first.first; i++) cs[i] -= maxw;
      ans += maxw;
    }

    cout << ans << nl;

    return 0;
}
