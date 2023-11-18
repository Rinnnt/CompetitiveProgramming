#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll x;
  while (cin >> x) {
    x *= 10000000;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0;
    int r = a.size() - 1;
    bool found = false;
    while (l < r) {
      if (a[l] + a[r] == x) {
        found = true;
        break;
      } else if (a[l] + a[r] > x) {
        r--;
      } else {
        l++;
      }
    }

    if (found)
      cout << "yes " << a[l] << " " << a[r] << nl;
    else
      cout << "danger" << nl;
  }

  return 0;
}
