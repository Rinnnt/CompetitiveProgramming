#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<bool> divides(10);
    for (int d = 1; d <= 9; d++) {
      if (n % d == 0) {
        divides[d] = true;
      }
    }
    for (int i = 0; i <= n; i++) {
      bool printed = false;
      for (int j = 1; j <= 9; j++) {
        if (divides[j]) {
          if (i % (n / j) == 0) {
            cout << j;
            printed = true;
            break;
          }
        }
      }
      if (!printed){
        cout << '-';
      }
    }

    return 0;
}
