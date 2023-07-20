#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  map<ll, ll> left;
  left[0]++;
  map<ll, ll> right;
  right[0]++;

  for (int i = 0; i < n / 2; i++) {
    map<ll, ll> lc(left);
    for (auto x : lc) {
      left[x.first + a[i]] += x.second;
    }
  }
  for (int i = n / 2; i < n; i++) {
    map<ll, ll> rc(right);
    for (auto x : rc) {
      right[x.first + a[i]] += x.second;
    }
  }

  ll ans = 0;
  for (auto x : left) {
    if (right.count(s - x.first)) {
      ans += x.second * right[s - x.first];
      //cout << "X: " << x.first << " " << x.second << nl;

      //cout << "Y: " << s - x.first << " " << right[s - x.first] << nl;
    }
  }

  if (s == 0) {
    cout << ans - 1;
  } else {
    cout << ans;
  }

  return 0;
}
