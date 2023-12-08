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

  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;

  while (r--) {
    string s;
    cin >> s;
    for (int i = 0; i < zr; i++) {
      for (auto c : s)
        for (int j = 0; j < zc; j++)
          cout << c;
      cout << nl;
    }
  }

  return 0;
}

