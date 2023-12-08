#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

map<string, int> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (m[s] > i - m[s])
      ans++;
    m[s]++;
  }

  cout << ans << nl;

  return 0;
}
