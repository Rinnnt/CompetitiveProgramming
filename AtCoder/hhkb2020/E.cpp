#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

bool board[2000][2000];
vector<int> rs[2000];
vector<int> cs[2000];

const ll mod = 1e9 + 7;

ll modpow(ll n, ll m) {
  ll ans = 1;
  while (m) {
    if (m & 1) ans = (ans * n) % mod;
    n = (n * n) % mod;
    m >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 2000; i++) {
    rs[i].push_back(-1);
    cs[i].push_back(-1);
  }

  int h, w;
  cin >> h >> w;

  int tidy = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      board[i][j] = s[j] == '.';
      tidy += s[j] == '.';
      if (!board[i][j]) {
        rs[i].push_back(j);
        cs[j].push_back(i);
      }
    }
  }

  for (int i = 0; i < 2000; i++) {
    rs[i].push_back(w);
    cs[i].push_back(h);
  }

  ll ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j]) {
        int ri = lower_bound(rs[i].begin(), rs[i].end(), j) - rs[i].begin();
        int ci = lower_bound(cs[j].begin(), cs[j].end(), i) - cs[j].begin();
        int rf = rs[i][ri] - rs[i][ri - 1] - 1;
        int cf = cs[j][ci] - cs[j][ci - 1] - 1;
        ans = (ans + (modpow(2, tidy) - modpow(2, tidy - (rf + cf - 1))) % mod) % mod;
      }
    }
  }

  cout << (ans + mod) % mod << nl;

  return 0;
}

