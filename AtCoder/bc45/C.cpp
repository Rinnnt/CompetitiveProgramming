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

  string s;
  cin >> s;

  ll ans = 0;
  for (int i = 0; i < (1 << s.size() - 1); i++) {
    ll sum = 0;
    ll cur = s[0] - '0';
    for (int j = 0; j < s.size() - 1; j++) {
      if ((i >> j) & 1) {
        sum += cur;
        cur = 0;
      } else {
        cur *= 10;
      }
      cur += s[j + 1] - '0';
    }
    sum += cur;
    ans += sum;
  }

  cout << ans << nl;

  return 0;
}

