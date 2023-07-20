#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll ans = 6;
  int n;
  cin >> n;
  for (int i = 11; i <= n; i++) {
    ans *= i;
  }

  cout << ans;

  return 0;
}
