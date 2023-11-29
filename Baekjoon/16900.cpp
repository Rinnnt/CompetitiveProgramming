#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  int k;
  cin >> s >> k;

  vector<int> p(s.size(), 0);
  for (int i = 1; i < s.size(); i++) {
    int j = p[i - 1];
    while (j > 0 && s[j] != s[i])
      j = p[j - 1];
    p[i] = j + (s[j] == s[i]);
  }

  cout << s.size() + (k - 1) * (s.size() - p[s.size() - 1]) << nl;

}
