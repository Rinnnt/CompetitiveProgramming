#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, ax, ay, bx, by;
vector<pair<int, int>> dxys;

bool inbound(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool reachable(pair<int, int> a, pair<int, int> b) {
  set<pair<int, int>> areach;
  set<pair<int, int>> reachb;

  areach.insert(a);
  reachb.insert(b);
  for (auto dxy : dxys) {
    int nx = a.first + dxy.first;
    int ny = a.second + dxy.second;
    if (inbound(nx, ny))
      areach.insert({nx, ny});
  }
  for (auto dxy : dxys) {
    int nx = b.first - dxy.first;
    int ny = b.second - dxy.second;
    if (inbound(nx, ny))
      reachb.insert({nx, ny});
  }

  set<pair<int, int>> intersect;
  set_intersection(areach.begin(), areach.end(), reachb.begin(), reachb.end(),
      inserter(intersect, intersect.begin()));

  return !intersect.empty();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> ax >> ay >> bx >> by;

  dxys.clear();
  for (int i = 0; i < n; i++) {
    int dx, dy;
    cin >> dx >> dy;
    dxys.push_back({dx, dy});
  }

  if (reachable({ax, ay}, {bx, by}))
    cout << "Alice wins" << nl;
  else {
    bool all = true;
    int x;
    int y;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, n);
    int checks = 0;
    while (checks < 30) {
      x = dist(gen);
      y = dist(gen);
      if (x == bx && y == by) continue;
      if (!reachable({bx, by}, {x, y})) {
        all = false;
        break;
      }
      checks++;
    }

    if (all)
      cout << "Bob wins" << nl;
    else
      cout << "tie " << x << " " << y << nl;
  }


  return 0;
}
