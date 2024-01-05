#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;

#define nl '\n'

int n, k;
ll a[1001];
vector<ll> sums;

int count(ll a) {
  int ret = 0;
  for (auto x : sums)
    if ((x & a) == a)
      ret++;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    ll acc = 0;
    for (int j = i; j < n; j++) {
      acc += a[j];
      sums.push_back(acc);
    }
  }

  ll mask = 0;
  for (int i = 40; i >= 0; --i)
    if (count(mask | (1LL << i)) >= k)
      mask |= (1LL << i);

  cout << mask << nl;

  return 0;
}

