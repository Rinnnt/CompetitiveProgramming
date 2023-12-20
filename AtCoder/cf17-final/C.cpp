#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int cnt[13];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    cnt[d]++;
  }

  if (cnt[0]) {
    cout << 0 << nl;
    return 0;
  }

  if (cnt[12] > 1) {
    cout << 0 << nl;
    return 0;
  }

  vector<bool> used(24, false);
  used[0] = true;
  vector<int> place;

  for (int i = 1; i <= 12; i++) {
    if (cnt[i] > 2) {
      cout << 0 << nl;
      return 0;
    } else if (cnt[i] == 2) {
      used[i] = used[24 - i] = true;
    } else if (cnt[i] == 1) {
      place.push_back(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << place.size()); i++) {
    vector<bool> tmp(used.begin(), used.end());
    bool valid = true;
    for (int j = 0; j < place.size(); j++) {
      int h = ((i >> j) & 1) ? place[j] : 24 - place[j];
      if (tmp[h]) {
        valid = false;
        break;
      }
      tmp[h] = true;
    }

    if (valid) {
      int diff = 24;
      int curdiff = 0;
      for (int j = 1; j <= 24; j++) {
        curdiff++;
        if (tmp[j % 24]) {
          diff = min(diff, curdiff);
          curdiff = 0;
        }
      }
      ans = max(ans, diff);
    }
  }

  cout << ans << nl;

  return 0;
}

