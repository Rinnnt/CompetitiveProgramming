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
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (idx == 0 || x > a[idx - 1]) {
      a[idx++] = x;
    } else {
      int l = lower_bound(a, a + idx, x) - a;
      a[l] = x;
    }
  }

  cout << idx;

  return 0;
}

