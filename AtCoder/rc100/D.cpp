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
  vector<ll> a(n + 1);
  vector<ll> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = a[i] + p[i - 1];
  }

  ll ans = 1e15;
  int l = 1;
  int r = 3;
  for (int i = 2; i < n - 1; i++) {
    while (abs(p[l + 1] - (p[i] - p[l + 1])) < abs(p[l] - (p[i] - p[l]))) {
      l++;
    }
    while (abs((p[r + 1] - p[i]) - (p[n] - p[r + 1])) < abs((p[r] - p[i]) - (p[n] - p[r]))) {
      r++;
    }
    ll mx = max(p[l], max(p[i] - p[l], max(p[r] - p[i], p[n] - p[r])));
    ll mn = min(p[l], min(p[i] - p[l], min(p[r] - p[i], p[n] - p[r])));
    ans = min(ans, mx - mn);
  }

  cout << ans << nl;

  return 0;
}
