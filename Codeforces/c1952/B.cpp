#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {

    string s;
    cin >> s;
    string ans = "NO";
    for (int i = 1; i < s.size(); i++) {
      if (s[i - 1] == 'i' && s[i] == 't') {
        ans = "YES";
      }
    }
    cout << ans << nl;

  }

  return 0;
}
