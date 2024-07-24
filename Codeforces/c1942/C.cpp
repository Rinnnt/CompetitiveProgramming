#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ps(x);
    for (auto &p : ps) cin >> p;

    sort(ps.begin(), ps.end());

    int ans = x - 2;
    for (int i = 1; i < x; i++)
      if (ps[i] - ps[i - 1] == 2)
        ans++;

    if (ps[x - 1] == n - 1 && ps[0] == 1)
      ans++;
    if (ps[x - 1] == n && ps[0] == 2)
      ans++;

    cout << ans << nl;
  }

  return 0;
}
