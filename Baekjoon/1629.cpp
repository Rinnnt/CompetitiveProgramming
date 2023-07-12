#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll pow(ll a, ll b, ll c) {
  if (b == 0) {
    return 1;
  }
  ll m = pow(a, b / 2, c);
  if (b % 2) {
    return (((m * m) % c) * a) % c;
  } else {
    return (m * m) % c;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;
  cout << pow(a, b, c);

  return 0;
}
