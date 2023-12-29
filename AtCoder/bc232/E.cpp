#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 998244353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll h, w, k;
  cin >> h >> w >> k;

  ll sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;

  ll start = 1;
  ll same_row = 0;
  ll same_column = 0;
  ll rest = 0;

  for (int i = 0; i < k; i++) {
    ll tmp_start = (((same_row * (w - 1)) % mod) + ((same_column * (h - 1)) % mod) % mod);
    ll tmp_same_row = (start + ((same_row * (w - 2)) % mod) + ((rest * (h - 1)) % mod)) % mod;
    ll tmp_same_column = (start + ((same_column * (h - 2)) % mod) + ((rest * (w - 1)) % mod)) % mod;
    ll tmp_rest = (same_column + same_row + ((h + w - 4) * rest % mod)) % mod;

    start = (tmp_start + mod) % mod;
    same_row = (tmp_same_row + mod) % mod;
    same_column = (tmp_same_column + mod) % mod;
    rest = (tmp_rest + mod) % mod;
  }

  if (sx == ex && sy == ey) {
    cout << start << nl;
  } else if (sx == ex) {
    cout << same_row << nl;
  } else if (sy == ey) {
    cout << same_column << nl;
  } else {
    cout << rest << nl;
  }


  return 0;
}

