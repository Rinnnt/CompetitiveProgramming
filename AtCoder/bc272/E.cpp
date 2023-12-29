#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<vector<int>> vals(m + 1);
  for (int i = 0; i < n; i++) {
    int j;
    if (a[i] < 0) {
      j = (-a[i] + i) / (i + 1);
    } else {
      j = 1;
    }
    a[i] += j * (i + 1);
    while (j < m + 1 && a[i] < n) {
      vals[j].push_back(a[i]);
      a[i] += i + 1;
      j++;
    }
  }

  for (int i = 1; i <= m; i++) {
    int sz = vals[i].size();
    vector<bool> exists(sz + 1);
    for (auto x : vals[i])
      if (x < sz)
        exists[x] = true;
    int mex = 0;
    while (exists[mex]) mex++;
    cout << mex << nl;
  }

  return 0;
}

