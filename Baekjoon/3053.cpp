#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ld r;
  cin >> r;

  ld area = r * r * M_PI;
  ld taxi_area = r * r * 2;

  cout << fixed << setprecision(15) << area << nl;

  cout << taxi_area << nl;

  return 0;
}
