#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> as(n);
    for (auto &a : as) cin >> a;

    vector<int> ds(n - 1);
    vector<int> rds(n - 1);
    for (int i = 0; i < n - 1; i++) {
      int d = abs(as[i + 1] - as[i]);
      ds[i] = (i & 1 ? -d : d);
      rds[i] = (i & 1 ? d : -d);
    }

    ll res = 0;

    ll ans = ds[0];
    ll sum = 0;

    for (int r = 0; r < n - 1; r++) {
      sum += ds[r];
      ans = max(ans, sum);
      sum = max(sum, 0LL);
    }

    res = ans;

    ans = rds[0];
    sum = 0;

    for (int r = 0; r < n - 1; r++) {
      sum += rds[r];
      ans = max(ans, sum);
      sum = max(sum, 0LL);
    }

    res = max(res, ans);

    cout << res << nl;

    return 0;
}
