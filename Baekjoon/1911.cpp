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

  int n, l;
  cin >> n >> l;
  vector<pii> ws(n);
  for (auto &w : ws) cin >> w.first >> w.second;

  sort(ws.begin(), ws.end());

  int ans = 0;
  int prev = -1;
  for (auto w : ws) {
    int left = max(prev, w.first);
    int need = (max(w.second - left, 0) + (l - 1)) / l;
    prev = left + need * l;
    ans += need;
  }

  cout << ans << nl;

  return 0;
}
