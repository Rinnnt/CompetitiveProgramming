#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int n;
vector<int> a;
vector<int> b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  a.resize(2 * n - 1);
  for (int i = n; i < 2 * n - 1; i++)
    a[i] = a[i - n];

  vector<int> ad(2 * (n - 1));
  vector<int> bd(n - 1);
  for (int i = 0; i < n - 1; i++) {
    ad[i] = a[i + 1] - a[i];
    bd[i] = b[i + 1] - b[i];
  }
  ad[n - 1] = 360000 + a[n] - a[n - 1];
  for (int i = n; i < 2 * (n - 1) - 1; i++)
    ad[i] = a[i + 1] - a[i];

  vector<int> c(3 * (n - 1) + 1);
  for(int i = 0; i < n - 1; i++)
    c[i] = bd[i];
  c[n - 1] = -1;
  for (int i = n; i < 3 * (n - 1) + 1; i++)
    c[i] = ad[i - n];

  bool pos = false;
  vector<int> p(3 * (n - 1) + 1);
  p[0] = 0;
  for (int i = 1; i < 3 * (n - 1) + 1; i++) {
    int j = p[i - 1];
    while (j > 0 && c[i] != c[j])
      j = p[j - 1];
    p[i] = (c[i] == c[j] ? ++j : j);

    if (p[i] == n - 1) {
      pos = true;
      break;
    }
  }

  if (pos)
    cout << "possible" << nl;
  else
    cout << "impossible" << nl;

  return 0;
}
