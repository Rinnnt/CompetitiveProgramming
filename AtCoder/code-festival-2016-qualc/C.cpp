#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

const ll mod = 1e9 + 7;

int t[100002];
int a[100002];
int l[100002];
int h[100002];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 100002; i++) {
    t[i] = a[i] = 0;
    l[i] = 1;
    h[i] = 1e9;
  }

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> t[i];
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++) {
    if (t[i] > t[i - 1]) {
      l[i] = max(l[i], t[i]);
      h[i] = min(h[i], t[i]);
    } else {
      h[i] = min(h[i], t[i]);
    }
  }

  for (int i = n; i > 0; i--) {
    if (a[i] > a[i + 1]) {
      l[i] = max(l[i], a[i]);
      h[i] = min(h[i], a[i]);
    } else {
      h[i] = min(h[i], a[i]);
    }
  }

  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans * max(0, h[i] - l[i] + 1)) % mod;
  }

  cout << ans << nl;

  return 0;
}

