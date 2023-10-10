#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

vector<pair<int, int>> points;

int ccw(int ax, int ay, int bx, int by) {
  int v = ax * by - ay * bx;
  if (v > 0) {
    return 1;
  } else if (v == 0) {
    return 0;
  } else {
    return -1;
  }
}

bool solve(vector<pair<int, int>> ps, int lines) {
  if (ps.size() <= lines) {
    return true;
  }

  for (int i = 0; i < lines + 1; i++) {
    for (int j = i + 1; j < lines + 1; j++) {
      int abx = ps[j].first - ps[i].first;
      int aby = ps[j].second - ps[i].second;

      vector<pair<int, int>> cps;
      for (int k = 0; k < ps.size(); k++) {
        int acx = ps[k].first - ps[i].first;
        int acy = ps[k].second - ps[i].second;

        if (ccw(abx, aby, acx, acy) != 0) {
          cps.push_back(ps[k]);
        }
      }

      if (solve(cps, lines - 1)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points.push_back({x, y});
    }

    if (solve(points, 3)) {
      cout << "possible" << nl;
    } else {
      cout << "impossible" << nl;
    }

    return 0;
}
