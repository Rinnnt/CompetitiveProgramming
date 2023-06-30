#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        bool sdx = (bx >= ax && cx >= ax) || (bx <= ax && cx <= ax);
        bool sdy = (by >= ay && cy >= ay) || (by <= ay && cy <= ay);

        ll result = 0;
        if (sdx) {
            ll bdx = abs(bx - ax);
            ll cdx = abs(cx - ax);
            result += min(bdx, cdx);
        }
        if (sdy) {
            ll bdy = abs(by - ay);
            ll cdy = abs(cy - ay);
            result += min(bdy, cdy);
        }
        cout << result  + 1 << nl;
    }

    return 0;
}
