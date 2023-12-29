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

  int h, w, n;
  cin >> h >> w >> n;
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  string s, t;
  cin >> s >> t;

  int l = 0, r = w - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (l == -1) continue;
    if (t[i] == 'L') {
      r = min(w - 1, r + 1);
    } else if (t[i] == 'R') {
      l = max(0, l - 1);
    }

    if (s[i] == 'L') {
      l++;
    } else if (s[i] == 'R') {
      r--;
    }
    if (l > r) l = -1, r = -1;
  }

  int u = 0, d = h - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (u == -1) continue;
    if (t[i] == 'U') {
      d = min(h - 1, d + 1);
    } else if (t[i] == 'D') {
      u = max(0, u - 1);
    }

    if (s[i] == 'U') {
      u++;
    } else if (s[i] == 'D') {
      d--;
    }
    if (u > d) u = -1, d = -1;
  }

  if (l <= y && y <= r && u <= x && x <= d) {
    cout << "YES" << nl;
  } else {
    cout << "NO" << nl;
  }
  return 0;
}
