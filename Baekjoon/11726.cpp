#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  if (n == 1) {
    return 1;
  }
  int prev = 1;
  int cur = 2;
  for (int i = 3; i <= n; i++) {
    swap(cur, prev);
    cur += prev;
    if (cur > 10007) {
      cur -= 10007;
    }
  }
  cout << cur << nl;

  return 0;
}
