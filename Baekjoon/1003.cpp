#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<ll> fibs(42);
  fibs[0] = 0;
  fibs[1] = 1;
  for (int i = 2; i < 42; i++) {
    fibs[i] = fibs[i - 2] + fibs[i - 1];
  }

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n == 0) {
      cout << "1 0" << nl;
    } else {
      cout << fibs[n - 1] << " " << fibs[n] << nl;
    }
  }

}
