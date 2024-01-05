#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

bool fnd = false;
vector<string> row[3];
vector<string> grid;
int n;
string r, c;

void dfs(int i, int fl) {
  if (fnd) return;
  if (i == n) {
    if (fl == 0) {
      cout << "Yes" << nl;
      for (auto x : grid) cout << x << nl;
      fnd = true;
    }
    return;
  }
  for (auto &x : row[r[i] - 'A']) {
    grid.push_back(x);

    int ufl = fl;
    bool und = true;
    for (int j = 0; j < n; j++) {
      if (x[j] == '.') continue;
      int kind = (x[j] - 'A');
      if ((fl & (1 << (4 * j + kind))) == 0) {
        und = false;
        break;
      }
      ufl ^= (1 << (4 * j + kind));
      if ((fl & (1 << (4 * j + 3))) != 0) {
        if (x[j] != c[j]) {
          und = false;
          break;
        }
        ufl ^= (1 << (4 * j + 3));
      }
    }

    if (und)
      dfs(i + 1, ufl);
    grid.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> r >> c;
  string abc = "ABC";
  while (abc.size() < n) abc.push_back('.');
  sort(abc.begin(), abc.end());

  do {
    char c;
    for (auto x : abc) {
      if (x != '.') {
        c = x;
        break;
      }
    }
    row[c - 'A'].push_back(abc);
  } while (next_permutation(abc.begin(), abc.end()));

  dfs(0, (1 << (4 * n)) - 1);
  if (!fnd) cout << "No" << nl;

  return 0;
}

