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

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  reverse(a.begin(), a.end());

  ll l = 2;
  ll h = 2;
  for (auto x : a) {
    ll lm = (l + x - 1) / x;
    ll hm = h / x;

    if (lm > hm) {
      cout << -1 << nl;
      return 0;
    }

    l = x * lm;
    h = x * hm + x - 1;
  }

  cout << l << " " << h << nl;

  return 0;
}

