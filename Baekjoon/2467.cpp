#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int l = 0;
  int r = n - 1;
  ll diff = 1e12;
  int b, c;
  while (r > l) {
    int sum = a[l] + a[r];
    if (sum == 0) {
      b = a[l];
      c = a[r];
      break;
    } else if (sum > 0) {
      if (sum < diff) {
        diff = sum;
        b = a[l];
        c = a[r];
      }
      r--;
    } else {
      if (-1 * sum < diff) {
        diff = -1 * sum;
        b = a[l];
        c = a[r];
      }
      l++;
    }
  }

  cout << b << " " << c;

  return 0;
}
