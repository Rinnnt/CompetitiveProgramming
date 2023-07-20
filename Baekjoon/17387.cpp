#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll ccw(ll x1, ll y1, ll x2, ll y2) {
  ll cross = x1 * y2 - x2 * y1;
  if (cross > 0) {
    return 1;
  } else if (cross < 0) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  ll abx = x2 - x1;
  ll aby = y2 - y1;
  ll acx = x3 - x1;
  ll acy = y3 - y1;
  ll adx = x4 - x1;
  ll ady = y4 - y1;

  ll abcccw = ccw(abx, aby, acx, acy);
  ll abdccw = ccw(abx, aby, adx, ady);

  bool intersects = false;
  bool possible = false;
  if (abcccw == 0) {
    if (x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2)) {
      intersects = true;
    }
  }
  if (abdccw == 0) {
    if (x4 >= min(x1, x2) && x4 <= max(x1, x2) && y4 >= min(y1, y2) && y4 <= max(y1, y2)) {
      intersects = true;
    }
  }
  if ((abcccw == 1 && abdccw == -1) || (abcccw == -1 && abdccw == 1)) {
    possible = true;
  }

  ll cdx = x4 - x3;
  ll cdy = y4 - y3;
  ll cax = x1 - x3;
  ll cay = y1 - y3;
  ll cbx = x2 - x3;
  ll cby = y2 - y3;

  ll cdaccw = ccw(cdx, cdy, cax, cay);
  ll cdbccw = ccw(cdx, cdy, cbx, cby);

  if (cdaccw == 0) {
    if (x1 >= min(x3, x4) && x1 <= max(x3, x4) && y1 >= min(y3, y4) && y1 <= max(y3, y4)) {
      intersects = true;
    }
  }
  if (cdbccw == 0) {
    if (x2 >= min(x3, x4) && x2 <= max(x3, x4) && y2 >= min(y3, y4) && y2 <= max(y3, y4)) {
      intersects = true;
    }
  }
  if ((cdaccw == 1 && cdbccw == -1) || (cdaccw == -1 && cdbccw == 1)) {
    if (possible) {
      intersects = true;
    }
  }

  cout << (intersects ? 1 : 0);

  return 0;
}
