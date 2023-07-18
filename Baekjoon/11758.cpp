#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int ax = x2 - x1;
  int ay = y2 - y1;
  int bx = x3 - x1;
  int by = y3 - y1;

  int k = ax * by - ay * bx;

  if (k == 0) {
    cout << 0;
  } else if (k > 0) {
    cout << 1;
  } else {
    cout << -1;
  }


  return 0;
}
