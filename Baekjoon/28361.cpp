#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(6);

  int n;
  cin >> n;
  cout << n << nl;

  int pos = 1;
  cout << pos << " ";
  if (n % 3 == 0) {
    int step = 0;
    while (step != n - 1) {
      if (step % 3 == 0) {
        pos += 2;
      } else if (step % 3 == 1) {
        pos -= 1;
      } else if (step % 3 == 2) {
        pos += 2;
      }
      step++;
      cout << pos << " ";
    }
    cout << 1;
  } else {
    pos += 1;
    cout << pos << " ";
    int step = 0;
    while (step != n - 2) {
      if (step % 3 == 0) {
        pos += 2;
      } else if (step % 3 == 1) {
        pos -= 1;
      } else if (step % 3 == 2) {
        pos += 2;
      }
      step++;
      cout << pos << " ";
    }
    cout << 1;

  }


  return 0;
}
