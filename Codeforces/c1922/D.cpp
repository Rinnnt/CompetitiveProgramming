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
      vector<int> as(n), ds(n);
      for (auto &a : as) cin >> a;
      for (auto &d : ds) cin >> d;
      set<int> lft, cur;

      for (int i = 0; i < n; i++) {
        lft.insert(i);
        cur.insert(i);
      }

      for (int i = 0; i < n; i++) {
        set<int> dead, ncur;
        for (auto x : cur) {
          auto it = lft.find(x);
          if (it == lft.end()) continue;
          int la = (it != lft.begin() ? as[*prev(it)] : 0);
          int ra = (next(it) != lft.end() ? as[*next(it)] : 0);
          if (la + ra > ds[x]) {
            dead.insert(x);
            if (it != lft.begin()) ncur.insert(*prev(it));
            if (next(it) != lft.end()) ncur.insert(*next(it));
          }
        }

        cout << dead.size() << " ";
        for (auto x : dead) lft.erase(x);
        cur = ncur;
      }
      cout << nl;

    }
 
    return 0;
}
