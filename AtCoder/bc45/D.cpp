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

  ll h, w, n;
  cin >> h >> w >> n;
  set<pii> painted;
  for (int i = 0; i < n; i++) {
    pii c;
    cin >> c.first >> c.second;
    painted.insert(c);
  }

  vector<ll> containsBlack(10, 0);
  set<pii> considered;

  for (auto c : painted) {
    int x = c.first;
    int y = c.second;

    for (int i = x - 2; i <= x; i++) {
      for (int j = y - 2; j <= y; j++) {
        if (considered.count({i, j})) continue;

        int cnt = 0;
        bool valid = true;
        for (int ii = i; ii < i + 3; ii++) {
          for (int jj = j; jj < j + 3; jj++) {
            if (ii < 1 || ii > h || jj < 1 || jj > w) valid = false;
            if (painted.count({ii, jj})) cnt++;
          }
        }


        if (valid) {
          considered.insert({i, j});
          containsBlack[cnt]++;
        }
      }
    }

  }

  int tot = 0;
  for (auto x : containsBlack) tot += x;

  containsBlack[0] = (h - 2) * (w - 2) - tot;

  for (auto x : containsBlack)
    cout << x << nl;

  return 0;
}

