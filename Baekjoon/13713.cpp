#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  reverse(s.begin(), s.end());

  vector<int> z = z_function(s);
  z[0] = s.size();

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;

    cout << z[n - q] << nl;
  }

  return 0;
}
