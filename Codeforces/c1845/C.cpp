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
        string s;
        cin >> s;
        ll n = s.size();
        ll m;
        cin >> m;
        string l, r;
        cin >> l >> r;

        ll cur_l = 0;
        ll cur_data = 0;
        set<ll> left;

        while (cur_data < s.size() && cur_l < m) {
            for (int i = l[cur_l]; i <= r[cur_l]; i++) {
                left.insert(i);
            }
            while (cur_data < s.size() && !left.empty()) {
                if (left.find(s[cur_data]) != left.end()) {
                    left.erase(s[cur_data]);
                }
                cur_data++;
            }
            if (left.empty()) {
                cur_l++;
            } else {
                break;
            }
        }

        if (cur_l >= m) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << nl;
    }

    return 0;
}
