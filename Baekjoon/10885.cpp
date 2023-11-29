#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

const ll mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    ll ans = -1e9;
    ll cmax = -1e9;
    int l = 0;
    int ln = -1, rn = - 1;
    int ns = 0;
    for (int r = 0; r < n + 1; r++) {
      if (a[r] == 0) {
        if (r != n)
          cmax = max(cmax, (ll)a[r]);
        if (ns % 2) {
          ll lans = 0;
          for (int i = l; i < rn; i++)
            if (abs(a[i]) == 2)
              lans++;
          ans = max(lans, ans);

          ll rans = 0;
          for (int i = ln + 1; i < r; i++)
            if (abs(a[i]) == 2)
              rans++;
          ans = max(rans, ans);
        } else {
          ll cans = 0;
          for (int i = l; i < r; i++)
            if (abs(a[i]) == 2)
              cans++;
          ans = max(cans, ans);
        }
        ln = -1;
        l = r + 1;
        ns = 0;
      } else {
        cmax = max(cmax, (ll)a[r]);
        if (a[r] < 0) {
          ns += 1;
          if (ln == -1)
            ln = r;
          rn = r;
        }
      }
    }

    ll res = cmax;
    if (ans != 0) {
      ll tmp = 1;
      for (int i = 0; i < ans; i++)
        tmp = (tmp * 2) % mod;
      res = max(res, tmp);
    } else {
      if (cmax <= 0) {
        int minusOnes = 0;
        for (int i = 0; i < n + 1; i++) {
          if (a[i] == 0) minusOnes = 0;
          if (a[i] == -1) minusOnes++;
          if (minusOnes == 2) res = 1;
        }
      }
    }
    cout << res << nl;
  }

  return 0;
}
