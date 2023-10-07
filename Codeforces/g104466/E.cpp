#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

string a;
char tmp[25];

void dfs(int si, int ti) {
    if (si >= a.size()) {
        for (int i = 0; i < ti; i++) {
            cout << tmp[i];
        }
        cout << nl;
        return;
    }

    tmp[ti] = tolower(a[si]);
    dfs(si + 1, ti + 1);
    if (si > 0 && a[si] == 'S' && tmp[ti - 1] == 's') {
        tmp[ti - 1] = 'B';
        dfs(si + 1, ti);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a;

    dfs(0, 0);

    return 0;
}
