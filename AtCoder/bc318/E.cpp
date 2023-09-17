#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int prevs[300001];
vector<int> gaps[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n; i++) {
        prevs[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (prevs[a[i]] != -1) {
            gaps[a[i]].push_back(i - prevs[a[i]] - 1);
        }
        prevs[a[i]] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int sz = gaps[i].size();
        for (int j = 0; j < sz; j++) {
            ans += ll(j + 1) * ll(gaps[i][j]) * ll(sz - j);
        }
    }

    cout << ans;

    return 0;
}
