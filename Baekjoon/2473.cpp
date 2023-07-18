#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  ll diff = 1e12;
  ll x, y, z;
  for (int i = 0; i < a.size(); i++) {
    int l = i + 1;
    int r = a.size() - 1;
    while (l < r) {
      ll ndiff = a[i] + a[l] + a[r];
      if (abs(ndiff) < diff) {
        diff = abs(ndiff);
        x = a[i];
        y = a[l];
        z = a[r];
      }
      if (ndiff > 0) {
        r--;
      } else {
        l++;
      }
    }
  }

  cout << x << " " << y << " " << z;

  return 0;
}
