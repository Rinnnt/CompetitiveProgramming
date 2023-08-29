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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        bool pc = k % 2 == 0;
        if (pc) {
            sort(s.begin(), s.end());
            cout << s << nl;
        } else {
            string evens = "";
            string odds = "";
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    odds += s[i];
                } else {
                    evens += s[i];
                }
            }
            sort(odds.begin(), odds.end());
            sort(evens.begin(), evens.end());
            string ans = "";
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    ans += odds[i / 2];
                } else {
                    ans += evens[i / 2];
                }
            }
            cout << ans << nl;
        }

    }

    return 0;
}
