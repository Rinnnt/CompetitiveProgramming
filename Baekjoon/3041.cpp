#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'
#define pii pair<int, int>

pii m[16] = {
  {0, 0},
  {0, 1},
  {0, 2},
  {0, 3},
  {1, 0},
  {1, 1},
  {1, 2},
  {1, 3},
  {2, 0},
  {2, 1},
  {2, 2},
  {2, 3},
  {3, 0},
  {3, 1},
  {3, 2},
  {3, 3},
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 4; j++) {
      if (s[j] != '.') {
        ans += abs(i - m[s[j] - 'A'].first) + abs(j - m[s[j] - 'A'].second);
      }
    }
  }

  cout << ans << nl;

  return 0;
}

