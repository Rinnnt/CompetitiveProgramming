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
  vector<ll> a(n);
  for (auto &x : a) cin >> x;

  ll mincost = 1e18;
  for (int i = -100; i < 101; i++) {
    ll cost = 0;
    for (auto x : a) {
      cost += (x - i) * (x - i);
    }
    mincost = min(mincost, cost);
  }

  cout << mincost << nl;

  return 0;
}

