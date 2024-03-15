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
  vector<pii> os(n);
  for (auto &o : os) cin >> o.first >> o.second;

  sort(os.begin(), os.end());

  int l, p;
  cin >> l >> p;

  priority_queue<int> seen;
  int oidx = 0;
  int cnt = 0;

  while (p < l) {
    while (oidx < n && os[oidx].first <= p)
      seen.push(os[oidx++].second);

    if (seen.empty()) {
      cnt = -1;
      break;
    } else {
      p += seen.top();
      seen.pop();
      cnt++;
    }
  }

  cout << cnt << nl;

  return 0;
}
