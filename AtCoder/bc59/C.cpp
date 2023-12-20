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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  ll sum = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (i % 2) {
      if (sum >= 0) {
        ans += sum + 1;
        sum = -1;
      }
    } else {
      if (sum <= 0) {
        ans += 1 - sum;
        sum = 1;
      }
    }
  }

  sum = 0;
  ll ans2 = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (i % 2 == 0) {
      if (sum >= 0) {
        ans2 += sum + 1;
        sum = -1;
      }
    } else {
      if (sum <= 0) {
        ans2 += 1 - sum;
        sum = 1;
      }
    }
  }

  cout << min(ans, ans2) << nl;

  return 0;
}

