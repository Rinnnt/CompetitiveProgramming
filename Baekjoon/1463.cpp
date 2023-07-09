#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n + 10);
  a[1] = 0;
  a[2] = 1;
  a[3] = 1;
  for (int i = 4; i <= n; i++) {
    a[i] = a[i - 1] + 1;
    if (i % 3 == 0) {
      a[i] = min(a[i], a[i / 3] + 1);
    }
    if (i % 2 == 0) {
      a[i] = min(a[i], a[i / 2] + 1);
    }
  }

  cout << a[n];
}
