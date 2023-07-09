#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll ans = 1;
    while (n--) {
      ans = (ans * 2) % ((ll)1e9 + 7);
    }
    cout << ans;

    return 0;
}