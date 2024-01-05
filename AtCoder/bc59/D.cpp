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

  ll x, y;
  cin >> x >> y;
  if (abs(x - y) <= 1)
    cout << "Brown" << nl;
  else
    cout << "Alice" << nl;

  return 0;
}

