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

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int len = s.size();

  vector<int> z = z_function(s);

  int best = 0;

  for (int i = 1; i <= n; i++) {
    if (i < len) {
      if (i + z[i] == len) {
        int rem = len % i;
        if (rem == 0 || i - rem <= k)
          best = i;
      }
    } else {
      if (2 * i <= len + k)
        best = i;
    }
  }

  cout << best << nl;

  return 0;
}
