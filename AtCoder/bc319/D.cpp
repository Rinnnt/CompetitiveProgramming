#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

ll n, m;
ll l[200005];

bool fits(ll w) {
  ll line = 1;
  ll cpos = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cpos++;
      if (cpos > w) {
        line++;
        cpos = 0;
      }
    }
    if (cpos + l[i] > w) {
      line++;
      cpos = l[i];
    } else {
      cpos += l[i];
    }
  }
  return line <= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    ll minlen = 0;
    for (int i = 0; i < n; i++) {
      cin >> l[i];
      minlen = max(minlen, l[i]);
    }

    ll l = minlen - 1;
    ll r = 1e16;
    while (l + 1 < r) {
      ll mid = (l + r) / 2;

      if (fits(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }

    cout << r;

    return 0;
}
