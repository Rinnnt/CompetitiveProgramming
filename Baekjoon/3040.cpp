#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> a(9);
  for (auto &x : a)
    cin >> x;

  int total = 0;
  for (auto x : a)
    total += x;

  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = i + 1; j < 9; j++) {
      if (total - a[i] - a[j] == 100)
        break;
    }
    if (j < 9 && total - a[i] - a[j] == 100)
      break;
  }

  for (int idx = 0; idx < 9; idx++)
    if (idx != i && idx != j)
      cout << a[idx] << nl;

  return 0;
}

