#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, c, o, d, i;
    cin >> t >> c >> o >> d >> i;
    vector<int> res;
    int l = t + c + o + d + i;
    int r = 4 * t + 6 * c + 8 * o + 12 * d + 20 * i;
    while (l < r) {
        res.push_back(l++);
        res.push_back(r--);
    }
    if (l == r) {
        res.push_back(l);
    }

    reverse(res.begin(), res.end());

    for (auto x : res) {
        cout << x << " ";
    }
    cout << nl;

    return 0;
}
