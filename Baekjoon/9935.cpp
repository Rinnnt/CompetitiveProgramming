#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s, p;
  cin >> s >> p;
  int plen = p.size();
  string c = p + "#";
  vector<int> pref(plen + s.size() + 5, 0);
  for (int i = 0; i < s.size(); i++) {
    c += s[i];
    int idx = c.size() - 1;
    int j = pref[idx - 1];
    while (j > 0 && c[j] != c[idx]) {
      j = pref[j - 1];
    }
    pref[idx] = (c[j] == c[idx] ? j + 1 : j);
    if (pref[idx] == plen) {
      c.erase(c.end() - plen, c.end());
    }
  }

  int ri = plen + 1;
  if (c.size() == ri) {
    cout << "FRULA";
  } else {
    cout << c.substr(ri);
  }

  return 0;
}
