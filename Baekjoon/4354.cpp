#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  while (s != ".") {
    int slen = s.size();
    vector<int> pref(slen, 0);
    for (int i = 1; i < slen; i++) {
      int j = pref[i - 1];
      while (j > 0 && s[i] != s[j]) {
        j = pref[j - 1];
      }
      pref[i] = (s[i] == s[j] ? j + 1 : j);
    }

    int cyclelen = slen - pref[slen - 1];
    if (slen % cyclelen) {
      cout << 1 << nl;
    } else {
      cout << slen / cyclelen << nl;
    }

    cin >> s;
  }

  return 0;
}
