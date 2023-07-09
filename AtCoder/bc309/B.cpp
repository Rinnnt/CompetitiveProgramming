#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<string> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = a[i];
    }

    for (int i = 1; i < n; i++) {
      res[0][i] = a[0][i - 1];
      res[i][n - 1] = a[i - 1][n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
      res[i][0] = a[i + 1][0];
      res[n - 1][i] = a[n - 1][i + 1];
    }

    for (int i = 0; i < n; i++) {
      cout << res[i] << nl;
    }

    return 0;
}
