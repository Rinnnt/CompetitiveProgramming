#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; 
  cin >> n;
  vector<int> t(n);
  for (auto &x : t) {
    cin >> x;
  }

  sort(t.begin(), t.end());

  ll sum = t[0];
  for (int i = 1; i < n; i++) {
    t[i] += t[i - 1];
    sum += t[i];
  }

  cout << sum << " ";

  return 0;
}
