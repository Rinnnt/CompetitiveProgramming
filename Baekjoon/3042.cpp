#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

bool p[30] = {};
pii pos[30];

int ccw(pii a, pii b, pii c) {
  int abx = b.first - a.first;
  int aby = b.second - a.second;

  int acx = c.first - a.first;
  int acy = c.second - a.second;

  return abx * acy - aby * acx;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c != '.') {
        pos[c - 'A'] = {i, j};
        p[c - 'A'] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 26; i++)
    for (int j = i + 1; j < 26; j++)
      for (int k = j + 1; k < 26; k++)
        if (p[i] && p[j] && p[k] && ccw(pos[i], pos[j], pos[k]) == 0)
          ans++;

  cout << ans << nl;

  return 0;
}

