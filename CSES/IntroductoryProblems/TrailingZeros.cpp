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
    for (ll i = 5; i <= n; i *= 5) {
      ans += n / i;
    }
    cout << ans;


    return 0;
}