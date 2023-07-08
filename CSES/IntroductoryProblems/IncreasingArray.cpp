#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;
    ll prevmax;
    cin >> prevmax;
    for (int i = 0; i < n - 1; i++) {
      ll x;
      cin >> x;
      ans += max(0LL, prevmax - x);
      prevmax = max(x, prevmax);
    }
    cout << ans;

    return 0;
}