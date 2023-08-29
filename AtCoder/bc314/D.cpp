#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    int lu = -1;
    vector<int> upd;
    for (int i = 0; i < q; i++) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        if (t == 1) {
            s[--x] = c;
            upd.push_back(x);
        } else if (t == 2) {
            lu = 0;
            upd.clear();
        } else {
            lu = 1;
            upd.clear();
        }
    }

    if (lu == -1) {
        cout << s;
    } else {
        string res = s;
        if (lu) {
            for (int i = 0; i < res.size(); i++) {
                res[i] = toupper(res[i]);
            }
        } else {
            for (int i = 0; i < res.size(); i++) {
                res[i] = tolower(res[i]);
            }
        }
        for (auto i : upd) {
            res[i] = s[i];
        }
        cout << res;
    }

    return 0;
}
