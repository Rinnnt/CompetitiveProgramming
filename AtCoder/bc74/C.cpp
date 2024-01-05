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

  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  vector<ll> sugars;
  for (int i = 0; i <= f / c; i++) {
    ll sugar = i * c;
    while (sugar <= f) {
      sugars.push_back(sugar);
      sugar += d;
    }
  }

  sort(sugars.begin(), sugars.end());

  ll densewater = a * 100;
  ll densesugar = 0;
  for (int i = 0; i <= f / 100 / a; i++) {
    ll water = 100 * i * a;
    while (water <= f) {
      ll maxsugar = min(f - water, e * water / 100);
      ll sugaridx = upper_bound(sugars.begin(), sugars.end(), maxsugar) - sugars.begin();
      ll sugar = sugars[sugaridx - 1];
      if (sugar * (densesugar + densewater) > densesugar * (sugar + water)) {
        densesugar = sugar;
        densewater = water;
      }

      water += b * 100;
    }
  }

  cout << densesugar + densewater << " " << densesugar << nl;

  return 0;
}

