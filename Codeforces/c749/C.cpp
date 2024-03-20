#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int d = 0;
    int r = 0;
    string s;
    cin >> s;
    for (auto c : s) {
      if (c == 'D') d++;
      else r++;
    }
    vector<bool> alive(n, true);

    int v = 0;
    int idx = 0;
    while (d > 0 && r > 0) {
      if (alive[idx]) {
        if (v < 0 && s[idx] == 'D') {
          alive[idx] = false;
          d--;
          v++;
        } else if (v > 0 && s[idx] == 'R') {
          alive[idx] = false;
          r--;
          v--;
        } else if (s[idx] == 'D') {
          v++;
        } else {
          v--;
        }
      }
      idx++;
      idx %= n;
    }

    if (d != 0) {
      cout << "D" << nl;
    } else {
      cout << "R" << nl;
    }

    return 0;
}
