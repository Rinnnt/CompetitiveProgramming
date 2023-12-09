#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());

  int l, r, i;

  vector<int> b(n);
  b[0] = a[(n - 1) / 2];
  i = 1;
  l = 0;
  r = n - 1;
  while (l < r) {
    b[i++] = a[r--];
    if (l != (n - 1) / 2) b[i++] = a[l++];
  }

  vector<int> c(n);
  c[0] = a[n / 2];
  i = 1;
  l = 0;
  r = n - 1;
  while (l < r) {
    c[i++] = a[l++];
    if (r != n / 2) c[i++] = a[r--];
  }

  ll bans = 0;
  for (int i = 0; i < n - 1; i++)
    bans += abs(b[i] - b[i + 1]);

  ll cans = 0;
  for (int i = 0; i < n - 1; i++)
    cans += abs(c[i] - c[i + 1]);

  cout << max(bans, cans) << nl;

  return 0;
}

