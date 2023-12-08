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

  int pos = 1;
  string s;
  cin >> s;
  for (auto x : s) {
    if (x == 'A') {
      if (pos == 1) pos = 2;
      else if (pos == 2) pos = 1;
    }
    if (x == 'B') {
      if (pos == 2) pos = 3;
      else if (pos == 3) pos = 2;
    }
    if (x == 'C') {
      if (pos == 1) pos = 3;
      else if (pos == 3) pos = 1;
    }
  }

  cout << pos << nl;

  return 0;
}

