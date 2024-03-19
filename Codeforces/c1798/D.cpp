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

      int n;
      cin >> n;

      multiset<int> as;
      for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        as.insert(a);
      }

      if (*as.begin() == 0) {
        cout << "No" << nl;
      } else {
        ll sum = 0;
        vector<int> ps;
        while (!as.empty()) {
          if (sum < 0) {
            ps.push_back(*prev(as.end()));
            sum += *prev(as.end());
            as.erase(prev(as.end()));
          } else {
            ps.push_back(*as.begin());
            sum += *as.begin();
            as.erase(as.begin());
          }
        }

        cout << "Yes" << nl;
        for (auto p : ps) cout << p << " ";
        cout << nl;
      }

    }

    return 0;
}
