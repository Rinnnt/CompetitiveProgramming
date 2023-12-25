#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << nl;
      return 0;
    }
  }

  for (int i = 0; i < n - 2; i++) {
    if (s[i] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << nl;
      return 0;
    }
  }

  cout << "-1 -1" << nl;

  return 0;
}

