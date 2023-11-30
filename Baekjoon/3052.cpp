#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'

bool rems[42] = {};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ans = 0;

  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;
    if (!rems[x % 42]) {
      ans++;
      rems[x % 42] = true;
    }
  }

  cout << ans << nl;

  return 0;
}
