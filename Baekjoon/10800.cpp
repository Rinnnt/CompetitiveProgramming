#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> b(n);
  vector<vector<int>> cb(n + 1, vector<int>());
  vector<vector<int>> p(n + 1);
  for (auto &x : b) {
    cin >> x.first >> x.second;
    cb[0].push_back(x.second);
    cb[x.first].push_back(x.second);
  }

  for (int i = 0; i <= n; i++) {
    sort(cb[i].begin(), cb[i].end());
    vector<int> pref(cb[i].size() + 1, 0);
    for (int j = 0; j < cb[i].size(); j++) {
      pref[j + 1] = pref[j] + cb[i][j];
    }
    p[i] = pref;
  }

  for (auto x : b) {
    int idx = lower_bound(cb[0].begin(), cb[0].end(), x.second) - cb[0].begin();
    int all = p[0][idx];
    idx = lower_bound(cb[x.first].begin(), cb[x.first].end(), x.second) - cb[x.first].begin();
    int same = p[x.first][idx];
    cout << all - same << nl;
  }



  return 0;
}
