#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h + 1);
  vector<vector<int>> pref(h + 1, vector<int>(w + 1, 0));
  for (int i = 1; i <= h; i++) {
    cin >> s[i];
    int c = 0;
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '1') c++;
      pref[i][j + 1] = pref[i - 1][j + 1] + c;
    }
  }

  int ans = 1e9;
  for (int mask = 0; mask < (1 << (h - 1)); mask++) {

    int cuts = __builtin_popcount(mask);

    int prevj = 0;
    bool valid = true;
    int j = 1;
    while (j <= w) {
      int previ = 0;
      bool over = false;
      for (int i = 1; i <= h; i++) {
        if ((mask >> (i - 1)) & 1) {
          if (pref[i][j] - pref[i][prevj] - pref[previ][j] + pref[previ][prevj] > k) {
            over = true;
          }
          previ = i;
        }
      }

      if (pref[h][j] - pref[h][prevj] - pref[previ][j] + pref[previ][prevj] > k) {
        over = true;
      }

      if (over) {
        if (prevj == j - 1) {
          valid = false;
          break;
        }
        cuts++;
        prevj = j - 1;
      } else {
        j++;
      }
    }

    if (valid) ans = min(ans, cuts);
  }

  cout << ans << nl;

  return 0;
}

