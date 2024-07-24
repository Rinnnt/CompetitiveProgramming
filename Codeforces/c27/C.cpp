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

  vector<int> as(n);
  for (auto &a : as) cin >> a;

  int prev_inc = -1;
  int prev_dec = -1;
  for (int i = 1; i < n; i++) {
    if (as[i] > as[i - 1]) {
      if (prev_dec != -1) {
        cout << 3 << nl;
        cout << prev_dec + 1 << " " << i << " " << i + 1 << nl;
        return 0;
      }
      prev_inc = i - 1;
    } else if (as[i] < as[i - 1]) {
      if (prev_inc != -1) {
        cout << 3 << nl;
        cout << prev_inc + 1 << " " << i << " " << i + 1 << nl;
        return 0;
      }
      prev_dec = i - 1;
    }
  }
  cout << 0 << nl;

  return 0;
}
