#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pref[i] = pref[i - 1] + x;
  }

  for (int k = 0; k < m; k++) {
    int i, j;
    cin >> i >> j;
    cout << pref[j] - pref[i - 1] << nl;
  }

}
