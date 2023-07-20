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
  int sum = 0;
  map<int, int> f;
  for (auto &x : a) {
    cin >> x;
    sum += x;
    f[x]++;
  }
  sort(a.begin(), a.end());

  int ma = 0;
  for (auto x : f) {
    ma = max(ma, x.first * x.second);
  }
  sum += ma;

  cout << sum << nl;
  for (auto x : a) {
    cout << x << " ";
  }


  return 0;
}
