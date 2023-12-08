#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  int A, B, C;
  A = min(a, min(b, c));
  C = max(a, max(b, c));
  B = a + b + c - A - C;

  string s;
  cin >> s;

  for (auto c : s) {
    if (c == 'A')
      cout << A;
    else if (c == 'B')
      cout << B;
    else
      cout << C;
    cout << " ";
  }

  cout << nl;

  return 0;
}
