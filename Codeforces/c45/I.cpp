#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> vs(n);
    vector<int> ps;
    multiset<int> ns;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      vs[i] = x;
      if (x > 0) {
        ps.push_back(x);
      } else if (x < 0) {
        ns.insert(x);
      } else {
        zeros++;
      }
    }

    vector<int> res;
    for (auto p : ps) res.push_back(p);
    while (ns.size() > 1) {
      for (int i = 0; i < 2; i++) {
        res.push_back(*ns.begin());
        ns.erase(ns.begin());
      }
    }

    if (res.empty()) {
      if (zeros) {
        res.push_back(0);
      } else {
        res.push_back(*prev(ns.end()));
      }
    }

    for (auto x : res)
      cout << x << " ";

    return 0;
}
