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

  vector<ll> a(n + 1, 0);
  vector<ll> b(n + 1, 0);
  vector<ll> c(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<ll> bc(n + 1);
  vector<ll> pbc(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    bc[i] = n + 1 - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
    pbc[i] = pbc[i - 1] + bc[i];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    ans += pbc[n] - pbc[idx - 1];
  }

  cout << ans << nl;

  return 0;
}

