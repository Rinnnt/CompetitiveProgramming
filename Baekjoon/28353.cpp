#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  int l = 0;
  int r = n - 1;
  int ans = 0;
  while (l < r) {
    if (a[l] + a[r] <= k) {
      l++;
      r--;
      ans++;
    } else {
      r--;
    }
  }

  cout << ans;

  return 0;
}
