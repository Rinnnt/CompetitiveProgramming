#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int tt = 0;
  vector<int> ts(n);
  for (auto &t : ts) {
    cin >> t;
    tt += t;
  }

  vector<ld> vs(n);
  for (auto &v : vs) cin >> v;

  vector<ld> l(2 * tt + 1);
  vector<ld> r(2 * tt + 1);
  l[0] = 0;
  int ct = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 2 * ts[k]; i++) {
      ct++;
      l[ct] = min(l[ct - 1] + 0.5, vs[k]);
    }
  }

  r[2 * tt] = 0;
  ct = 2 * tt;
  for (int k = n - 1; k >= 0; k--) {
    for (int i = 0; i < 2 * ts[k]; i++) {
      ct--;
      r[ct] = min(r[ct + 1] + 0.5, vs[k]);
    }
  }

  ld ans = 0;
  for (int i = 1; i < 2 * tt + 1; i++) {
    ans += ((ld)(min(l[i], r[i]) + min(l[i - 1], r[i - 1]))) / 4;
  }

  cout << fixed << setprecision(12) << ans << nl;

  return 0;
}

