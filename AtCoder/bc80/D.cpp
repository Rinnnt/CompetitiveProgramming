#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int used[30] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, C;
  cin >> n >> C;
  vector<int> s(n), t(n), c(n);
  vector<pair<int, int>> e;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i] >> c[i];
    e.push_back({2 * s[i] - 1, c[i]});
    e.push_back({2 * t[i], -c[i]});
  }

  sort(e.begin(), e.end());

  int ans = 0;
  int res = 0;
  for (auto v : e) {
    if (v.second > 0) {
      if (used[v.second] == 0)
        ans++;
      used[v.second]++;
    } else {
      used[-v.second]--;
      if (used[-v.second] == 0)
        ans--;
    }
    res = max(res, ans);
  }

  cout << res << nl;

  return 0;
}
