#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    set<pair<int, int>> covered;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int x = a; x < b; x++) {
            for (int y = c; y < d; y++) {
                covered.insert({x, y});
            }
        }
    }

    cout << covered.size();

    return 0;
}
