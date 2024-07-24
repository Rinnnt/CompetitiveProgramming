#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

ll t[3][3][4][64] = {};

bool beats(ll a, ll b) {
  a++;
  b++;
  return (a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll k, a, b;
    cin >> k >> a >> b;
    a--;
    b--;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> t[i][j][0][0];
        t[i][j][0][0]--;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> t[i][j][1][0];
        t[i][j][1][0]--;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (beats(i, j)) t[i][j][2][0]++;
        if (beats(j, i)) t[i][j][3][0]++;
      }
    }
    for (int k = 1; k < 64; k++) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          ll ni = t[i][j][0][k - 1];
          ll nj = t[i][j][1][k - 1];
          ll aws = t[i][j][2][k - 1];
          ll bws = t[i][j][3][k - 1];
          t[i][j][0][k] = t[ni][nj][0][k - 1];
          t[i][j][1][k] = t[ni][nj][1][k - 1];
          t[i][j][2][k] = aws + t[ni][nj][2][k - 1];
          t[i][j][3][k] = bws + t[ni][nj][3][k - 1];
        }
      }
    }

    ll taws = 0;
    ll tbws = 0;
    ll ca = a;
    ll cb = b;
    for (int i = 62; i >= 0; i--) {
      if ((1LL << i) <= k) {
        ll na = t[ca][cb][0][i];
        ll nb = t[ca][cb][1][i];
        taws += t[ca][cb][2][i];
        tbws += t[ca][cb][3][i];
        ca = na;
        cb = nb;
        k -= (1LL << i);
      }
    }

    cout << taws << " " << tbws << nl;

    return 0;
}
