#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll ask(int x, int y) {
  cout << x << " " << y << endl;
  ll d; cin >> d;
  return d;
}

void find() {
  ll d;
  if ((d = ask(0, 0)) == 0) return;
  for (ll x = 0; x * x <= d; x++) {
    ll y = sqrt(d - x * x);
    if (x <= 1000000 && y <= 1000000 && x * x + y * y == d)
      if (ask(x, y) == 0)
        return;
  }
}

int main() {
  int n;
  cin >> n;
  while (n--)
    find();

  return 0;
}
