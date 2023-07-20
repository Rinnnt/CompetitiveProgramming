#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  set<string> days;
  set<int> to = {1, 3, 5, 7, 8, 10, 12};
  set<int> ty = {4, 6, 9, 11};
  for (int x = 1; x <= 12; x++) {
    if (to.count(x)) {
      for (int y = 1; y <= 31; y++) {
        days.insert(to_string(x)  + "#" + to_string(y));
      }
    } else if (ty.count(x)) {
      for (int y = 1; y <= 30; y++) {
        days.insert(to_string(x)  + "#" + to_string(y));
      }
    } else {
      for (int y = 1; y <= 29; y++) {
        days.insert(to_string(x)  + "#" + to_string(y));
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    vector<bool> n(10);
    for (int i = 0; i < 10; i++) {
      int x;
      cin >> x;
      if (x) {
        n[i] = true;
      } else {
        n[i] = false;
      }
    }

    int ans = 0;
    for (auto x : days) {
      bool possible = true;
      for (auto c : x) {
        if (c != '#' && n[c - '0']) {
          possible = false;
        }
      }
      if (possible) {
        ans++;
      }
    }

    cout << ans << nl;
  }

  return 0;
}
