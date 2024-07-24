#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> ss(n), gs(n);
    for (int i = 0; i < n; i++)
      cin >> ss[i] >> gs[i];

    vector<int> ls(n, -1e9), hs(n, 1e9);
    int l = -1e9;
    int h = 1e9;
    for (int i = 0; i < n; i++) {
      ls[i] = max(ls[i], l);
      hs[i] = min(hs[i], h);
      l = max(l - 1, ss[i] - 1);
      h = min(h + 1, ss[i] + gs[i] + 1);
    }

    l = -1e9;
    h = 1e9;
    for (int i = n - 1; i >= 0; i--) {
      ls[i] = max(ls[i], l);
      hs[i] = min(hs[i], h);
      l = max(l - 1, ss[i] - 1);
      h = min(h + 1, ss[i] + gs[i] + 1);
    }

    bool possible = true;
    ll total = 0;
    for (int i = 0; i < n; i++) {
      if (ss[i] > hs[i] || ss[i] + gs[i] < ls[i]) {
        possible = false;
        break;
      }
      int r = min(ss[i] + gs[i], hs[i]) - ss[i];
      total += r;
      ss[i] += r;
    }

    if (possible) {
      cout << total << nl;
      for (auto s : ss) cout << s << " ";
      cout << nl;
    } else {
      cout << -1 << nl;
    }

    return 0;
}
