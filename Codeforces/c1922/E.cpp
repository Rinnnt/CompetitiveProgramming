#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

vector<int> f(ll x) {
  vector<int> res;
  if (x == 2) {
    res.push_back(0);
  } else if (x & 1) {
    res = f(x - 1);
    res.push_back(*min_element(res.begin(), res.end()) - 1);
  } else {
    res = f(x / 2);
    res.push_back(*max_element(res.begin(), res.end()) + 1);
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

      ll x;
      cin >> x;
      auto ans = f(x);
      cout << ans.size() << nl;
      for (auto i : ans) cout << i << ' ';
      cout << nl;

    }
 
    return 0;
}
