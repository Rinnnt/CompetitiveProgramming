#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> ps(n);
  for (auto &p : ps) cin >> p;

  sort(ps.begin(), ps.end());

  vector<int> ds(n - 1);
  for (int i = 1; i < n; i++) ds[i - 1] = ps[i] - ps[i - 1];

  sort(ds.begin(), ds.end());

  int ans = ps.back() - ps[0];
  for (int i = 0; i < k - 1; i++)
    if (n - i - 2 >= 0)
      ans -= ds[n - i - 2];

  cout << ans << nl;

  return 0;
}
