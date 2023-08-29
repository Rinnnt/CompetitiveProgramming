#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }

    vector<char> ch(m + 1, ' ');

    string res = s;
    for (int i = 0; i < s.size(); i++) {
        res[i] = ch[c[i]];
        ch[c[i]] = s[i];
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == ' ') {
            res[i] = ch[c[i]];
        }
    }

    cout << res;

    return 0;
}
