#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    int ans = 0;
    while (m <= n) {
      ans++;
      m += p;
    }

    cout << ans;

    return 0;
}
