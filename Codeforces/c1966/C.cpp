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
    vector<int> as(n);
    for (auto &a : as) cin >> a;

    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());

    vector<int> ds(1, as[0]);
    for (int i = 1; i < as.size(); i++) {
      ds.push_back(as[i] - as[i - 1]);
    }

    bool first = true;
    for (int i = ds.size() - 2; i >= 0; i--) {
      if (!first || ds[i] > 1) {
        first = true;
      } else {
        first = false;
      }
    }

    if (first) {
      cout << "Alice" << nl;
    } else {
      cout << "Bob" << nl;
    }

  }

  return 0;
}
