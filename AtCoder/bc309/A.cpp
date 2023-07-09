#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;

    if ((b - a == 1) && ((a >= 1 && b <= 3) || (a >= 4 && b <= 6) || (a >= 7 && b <= 9))) {
      cout << "Yes" << nl;
    } else {
      cout << "No" << nl;
    }


    return 0;
}
