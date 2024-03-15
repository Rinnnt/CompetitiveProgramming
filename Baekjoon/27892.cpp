#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> pattern1 = {7, 8, 2};
    vector<int> pattern2 = {6, 5, 12, 0};

    ull x, N;
    cin >> x >> N;

    while (N > 0 && x >= 8) {
      if (x & 1) {
        if (N < 3) break;
        N -= 3;
        x >>= 1;
        x ^= 4;
      } else {
        N--;
        x >>= 1;
        x ^= 6;
      }
    }

    if (N < 3) {
      while (N) {
        N--;
        if (x & 1) x <<= 1;
        else x >>= 1;
        x ^= 6;
      }
      cout << x << nl;
    } else {
      if (x == 0) cout << pattern2[(N - 1) % 4] << nl;
      if (x == 1) cout << 4 << nl;
      if (x == 2) cout << pattern1[(2 + N) % 3] << nl;
      if (x == 3) cout << pattern2[(N - 2) % 4] << nl;
      if (x == 4) cout << 4 << nl;
      if (x == 5) cout << pattern2[(1 + N) % 4] << nl;
      if (x == 6) cout << pattern2[N % 4] << nl;
      if (x == 7) cout << pattern1[N % 3] << nl;
    }

    return 0;
}
