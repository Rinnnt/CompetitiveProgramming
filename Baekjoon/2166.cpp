#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(1);

  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (auto &x : p) {
    cin >> x.first >> x.second;
  }

  int ox = p[0].first;
  int oy = p[0].second;
  double area = 0.0;
  for (int i = 1; i < n - 1; i++) {
    double ax = p[i].first - ox;
    double ay = p[i].second - oy;
    double bx = p[i + 1].first - ox;
    double by = p[i + 1].second - oy;

    area += (ax * by - ay * bx) / 2.0;
  }

  cout << fabs(area) << nl;

  return 0;
}
