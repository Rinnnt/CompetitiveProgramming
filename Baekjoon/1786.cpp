#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string t, p;
  getline(cin, t);
  getline(cin, p);
  int plen = p.size();

  string c = p + "#" + t;
  vector<int> idxs;
  int matches = 0;
  vector<int> pref(c.size(), 0);
  for (int i = 1; i < c.size(); i++) {
    int j = pref[i - 1];

    while (j > 0 && c[j] != c[i]) {
      j = pref[j - 1];
    }

    pref[i] = j + (c[i] == c[j]);
    if (pref[i] == plen) {
      matches++;
      idxs.push_back(i - 2 * plen + 1);
    }
  }

  cout << matches << nl;
  for (auto x : idxs) {
    cout << x << " ";
  }

  return 0;
}
