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
        s = "0" + s;
        int idx = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= '5') {
                for (int j = i; j < s.size(); j++) {
                    s[j] = '0';
                }
                s[i - 1] += 1;
                idx = i - 1;
                break;
            }
        }
        while (idx != -1 && s[idx] >= '5') {
            s[idx] = '0';
            s[--idx] += 1;
        }
        if (s[0] == '0') {
            cout << s.substr(1) << nl;
        } else {
            cout << s << nl;
        }
    }

    return 0;
}
