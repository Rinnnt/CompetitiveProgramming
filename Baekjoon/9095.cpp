#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> ans(11);
  ans[0] = 0;
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 4;

  for (int i = 4; i < 11; i++) {
    ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << nl;
  }
}
