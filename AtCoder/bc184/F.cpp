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

  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;

  set<ll> left;
  left.insert(0LL);
  for (int i = 0; i < n / 2; i++) {
    vector<ll> tmp;
    for (auto x : left)
      if (x + a[i] <= t)
        tmp.push_back(x + a[i]);

    for (auto x : tmp)
      left.insert(x);
  }

  set<ll> right;
  right.insert(0LL);
  for (int i = n / 2; i < n; i++) {
    vector<ll> tmp;
    for (auto x : right)
      if (x + a[i] <= t)
        tmp.push_back(x + a[i]);

    for (auto x : tmp)
      right.insert(x);
  }

  ll ans = *--left.upper_bound(t);
  ans = max(ans, *--right.upper_bound(t));

  for (auto x : right) {
    ans = max(ans, x + *--left.upper_bound(t - x));
  }

  cout << ans << nl;

  return 0;
}

