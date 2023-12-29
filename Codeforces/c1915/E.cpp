#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> p(n + 1);
    set<ll> prefs;
    prefs.insert(0);
    bool pos = false;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i % 2)
        a[i] *= -1;
      p[i] = p[i - 1] + a[i];
      if (prefs.count(p[i])) {
        pos = true;
      }
      prefs.insert(p[i]);
    }
    if (pos)
      cout << "YES" <<nl;
    else
      cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      solve();
    }

    return 0;
}
