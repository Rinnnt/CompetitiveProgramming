#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

bool binary_decimal(int x) {
  bool res = true;
  while (x) {
    if (x % 10 > 1) res = false;
    x /= 10;
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    vector<int> bin_decimals;
    for (int i = 100000; i > 1; i--)
      if (binary_decimal(i))
        bin_decimals.push_back(i);

    ll t;
    cin >> t;
    while (t--) {

      int n;
      cin >> n;

      for (auto bind : bin_decimals) {
        while (n % bind == 0)
          n /= bind;
      }


      if (n == 1) {
        cout << "YES" << nl;
      } else {
        cout << "NO" << nl;
      }

    }

    return 0;
}
