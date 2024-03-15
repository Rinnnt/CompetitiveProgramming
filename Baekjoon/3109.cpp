#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int r, c;
char b[10001][501];
bool used[10001][501];

bool dfs(int x, int y) {
  used[x][y] = true;
  if (y == c - 1) return true;

  for (int i = -1; i < 2; i++) {
    if (x + i >= 0 && x + i < r && !used[x + i][y + 1] && b[x + i][y + 1] == '.') {
      if (dfs(x + i, y + 1)) return true;
    }
  }
  return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < c; j++) {
        b[i][j] = s[j];
      }
    }

    int pipes = 0;
    for (int si = 0; si < r; si++) {
      if (dfs(si, 0)) pipes++;
    }

    cout << pipes << nl;

    return 0;
}
