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
  vector<int> lis;
  int len = 0;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
    if (idx == len) {
      lis.push_back(a[i]);
      len++;
    } else {
      lis[idx] = a[i];
    }
  }

  cout << len;

  return 0;
}
