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
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[i] = a[i];
  }

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for (auto x : a) {
    cout << lower_bound(c.begin(), c.end(), x) - c.begin() << " ";
  }

  return 0;
}
