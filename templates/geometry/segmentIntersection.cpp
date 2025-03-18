#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define nl '\n'

ll cross_product(pll a, pll b) {
    return a.first * b.second - a.second * b.first;
}

ll ccw(pll a, pll b, pll c) {
    pll ab = {b.first - a.first, b.second - a.second};
    pll bc = {c.first - b.first, c.second - b.second};

    ll cp = cross_product(ab, bc);
    if (cp > 0) return 1;
    else if (cp == 0) return 0;
    else return -1;
}

// pre: p q and r are collinear
ll between(pll p, pll q, pll r) {
    return q.first >= min(p.first, r.first) && q.first <= max(p.first, r.first) && q.second >= min(p.second, r.second) && q.second <= max(p.second, r.second);
}

bool intersects(pll p1, pll q1, pll p2, pll q2) {
    ld ansx, ansy;
    if (p1 > q1) swap(p1, q1);
    if (p2 > q2) swap(p2, q2);

    ll o1 = ccw(p1, q1, p2);
    ll o2 = ccw(p1, q1, q2);
    ll o3 = ccw(p2, q2, p1);
    ll o4 = ccw(p2, q2, q1);

    if (o1 != o2 && o3 != o4) {
        ld m1 = ((ld)(q1.second - p1.second)) / (q1.first - p1.first);
        ld c1 = ((ld)p1.second) - m1 * p1.first;
        ld m2 = ((ld)(q2.second - p2.second)) / (q2.first - p2.first);
        ld c2 = ((ld)p2.second) - m2 * p2.first;

        if (p1.first == q1.first) ansx = p1.first, ansy = m2 * p1.first + c2;
        else if (p2.first == q2.first) ansx = p2.first, ansy = m1 * p2.first + c1;
        else ansx = (c2 - c1) / (m1 - m2), ansy = m1 * ansx + c1;
        cout << 1 << nl;
        cout << ansx << " " << ansy << nl;
        return true;
    }

    if (o1 == 0 && between(p1, p2, q1)) {
        cout << 1 << nl;
        if (p2 == q1) cout << p2.first << " " << p2.second << nl;
        return true;
    }

    if (o2 == 0 && between(p1, q2, q1)) {
        cout << 1 << nl;
        if (q2 == p1) cout << p1.first << " " << p1.second << nl;
        return true;
    }

    if (o3 == 0 && between(p2, p1, q2)) {
        cout << 1 << nl;
        if (p1 == q2) cout << p1.first << " " << p1.second << nl;
        return true;
    }

    if (o4 == 0 && between(p2, q1, q2)) {
        cout << 1 << nl;
        if (q1 == p2) cout << p2.first << " " << p2.second << nl;
        return true;
    }

    cout << 0 << nl;
    return false;
}

void solveproblem() {
    pll p1, p2, p3, p4;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
    cin >> p4.first >> p4.second;

    cout << fixed << setprecision(9);
    intersects(p1, p2, p3, p4);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solveproblem();
    }
    
    return 0;
}
