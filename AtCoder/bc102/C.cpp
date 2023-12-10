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
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= (i + 1);
  }

  sort(a.begin(), a.end());

  ll b = a[n / 2];

  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += abs(a[i] - b);

  cout << ans << nl;

  return 0;
}

