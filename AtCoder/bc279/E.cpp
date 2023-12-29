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

  int n, m;
  cin >> n >> m;

  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    a[i] = i;

  vector<pii> swp(m);

  for (int i = 0; i < m; i++) {
    swp[i] = {a[b[i]], a[b[i] + 1]};
    swap(a[b[i]], a[b[i] + 1]);
  }

  vector<int> idx(n + 1);
  for (int i = 1; i <= n; i++)
    idx[a[i]] = i;

  for (int i = 0; i < m; i++) {
    if (min(swp[i].first, swp[i].second) == 1) {
      cout << idx[max(swp[i].first, swp[i].second)] << nl;
    } else {
      cout << idx[1] << nl;
    }
  }



  return 0;
}
