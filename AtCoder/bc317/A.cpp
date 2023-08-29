#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, h, x;
    cin >> n >> h >> x;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (h + a[i] >= x) {
        ans = i + 1;
        break;
      }
    }

    cout << ans << nl;

    return 0;
}
