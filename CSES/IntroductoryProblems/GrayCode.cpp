#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int getBit(int n, int idx) {
  return (n >> idx) & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int m = 1;
    for (int i = 0; i < n; i++) {
      m *= 2;
    }

    for (int i = 0; i < m; i++) {
      for (int j = n - 1; j >= 0; j--) {
        cout << (getBit(i, j) ^ getBit(i, j + 1));
      }
      cout << nl;
    }



    return 0;
}