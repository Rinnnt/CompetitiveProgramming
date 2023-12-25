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

  string s;
  cin >> s;

  ll m;
  cin >> m;

  int d = 0;
  for (auto c : s)
    d = max(d, c - '0');

  if (s.size() == 1) {
    if (d <= m)
      cout << 1 << nl;
    else
      cout << 0 << nl;
  } else {
    ll l = d;
    ll r = m + 1;
    while (l + 1 < r) {
      ll mid = (l + r) / 2;
      ll sum = 0;
      bool big = false;
      for (int i = 0; i < s.size(); i++) {
        if (sum > m / mid) big = true;
        sum *= mid;
        sum += s[i] - '0';
      }

      if (sum > m) big = true;

      if (big)
        r = mid;
      else
        l = mid;
    }

    cout << l - d << nl;
  }

  return 0;
}

