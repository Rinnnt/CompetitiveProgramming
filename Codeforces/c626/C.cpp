#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    // n <= floor(x / 2)
    // m <= floor(x / 3)
    // n + m <= floor(x / 2) + floor(x / 3) - floor(x / 6)
    for (int i = 3 * m; i <= 2 * n + 3 * m; i++) {
      if (i / 2 >= n && i / 3 >= m && i / 2 + i / 3 - i / 6 >= n + m) {
        cout << i << nl;
        break;
      }
    }

    return 0;
}
