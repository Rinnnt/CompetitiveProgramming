#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout << setprecision(12);

    double n;
    cin >> n;
    double ans = 1.0;
    ans += (n - 2) / 2;
    ans /= n - 1;

    cout << ans;

    return 0;
}
