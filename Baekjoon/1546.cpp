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
  int m = 0;
  for (auto &x : a) {
    cin >> x;
    m = max(m, x);
  }

  double sum = 0;
  for (auto x : a) {
    sum += (100.0 * x) / m;
  }

  cout << sum / n;
}
