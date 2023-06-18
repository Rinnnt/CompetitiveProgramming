#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
      int n, k;
      cin >> n >> k;

      int res = n + 1;
      int temp = 1;
      int i = 0;
      while (i < k) {
        temp *= 2;
        i++;
        if (temp > res) {
          break;
        }
      }

      cout << (temp < res ? temp : res) << '\n';
    }

    return 0;
}
