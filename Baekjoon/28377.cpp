#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

int frog[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n; 
    set<int> free;
    for (int i = 0; i < n; i++) {
        cin >> frog[i];
    }
    for (int i = 1; i < n; i++) {
        for (int pos = frog[i - 1] + 1; pos < frog[i]; pos++) {
            free.insert(pos);
        }
    }
    for (int pos = frog[n - 1] + 1; pos < frog[n - 1] + 200005; pos++) {
        free.insert(pos);
    }

    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        i--;
        auto it = free.lower_bound(frog[i] + 1);
        free.insert(frog[i]);
        frog[i] = *it;
        free.erase(it);
        cout << frog[i] << nl;
    }

    return 0;
}
