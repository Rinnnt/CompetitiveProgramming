#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<int, vector<int>> bet;
    vector<int> betcnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++) {
            int b;
            cin >> b;
            bet[b].push_back(i);
        }
        betcnt[i] = c;
    }

    int x;
    cin >> x;

    vector<int> res;
    int minbetcnt = 100;
    for (auto x : bet[x]) {
        if (betcnt[x] < minbetcnt) {
            res.clear();
            res.push_back(x);
            minbetcnt = betcnt[x];
        } else if (betcnt[x] == minbetcnt) {
            res.push_back(x);
        }
    }

    cout << res.size() << nl;
    if (res.size()) {
        for (auto x : res) {
            cout << x << " ";
        }
    }

    return 0;
}
