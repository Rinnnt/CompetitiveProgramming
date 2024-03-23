#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int bitstring(string s) {
  int res = 0;
  for (auto a : s)
    res = res ^ (1 << (a - 'a'));
  return res;
}

int m[1 << 26] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      int b = bitstring(s);
      vector<int> bs;
      bs.push_back(b);
      for (int i = 0; i < 26; i++)
        bs.push_back(b ^ (1 << i));

      for (auto x : bs)
        ans += m[x];

      m[b]++;
    }

    cout << ans << nl;

    return 0;
}

