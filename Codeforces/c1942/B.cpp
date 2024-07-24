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

    vector<int> ps(n);
    int mex = 0;
    for (int i = 0; i < n; i++) {
      if (as[i] < 0) {
        ps[i] = mex - as[i];
      } else {
        ps[i] = mex;
        mex += as[i];
      }
    }

    for (auto p : ps)
      cout << p << " ";
    cout << nl;

  }

  return 0;
}
