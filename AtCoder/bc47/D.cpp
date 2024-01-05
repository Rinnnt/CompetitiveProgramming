#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, t;
  cin >> n >> t;
  set<int> a;
  int maxdiff = 0;
  int maxdiffcnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (!a.empty()) {
      if (x - *a.begin() > maxdiff) {
        maxdiff = x - *a.begin();
        maxdiffcnt = 1;
      } else if (x - *a.begin() == maxdiff) {
        maxdiffcnt++;
      }
    }
    a.insert(x);
  }

  cout << maxdiffcnt << nl;

  return 0;
}

