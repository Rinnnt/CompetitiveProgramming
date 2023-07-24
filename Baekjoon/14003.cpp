#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[1000001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int idx = 0;
  map<int, int> p;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (idx == 0 || x > a[idx - 1]) {
      a[idx] = x;
      p[x] = idx ? a[idx - 1] : -1;
      idx++;
    } else {
      int l = lower_bound(a, a + idx, x) - a;
      a[l] = x;
      p[x] = l ? a[l - 1] : -1;
    }
  }

  cout << idx << nl;
  for (int i = idx - 1; i > 0; i--) {
    a[i - 1] = p[a[i]];
  }
  for (int i = 0; i < idx; i++) {
    cout << a[i] << " ";
  }

  return 0;
}

