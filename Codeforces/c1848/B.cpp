#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int pre[200005];
pair<int, int> gaps[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            pre[i] = 0;
            gaps[i].first = gaps[i].second = 0;
        }
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            int gap = i - pre[x] - 1;
            if (gap > gaps[x].first) {
                gaps[x].second = gaps[x].first;
                gaps[x].first = gap;
            } else if (gap > gaps[x].second) {
                gaps[x].second = gap;
            }
            pre[x] = i;
        }
        for (int x = 1; x <= k; x++) {
            int gap = n + 1 - pre[x] - 1;
            if (gap > gaps[x].first) {
                gaps[x].second = gaps[x].first;
                gaps[x].first = gap;
            } else if (gap > gaps[x].second) {
                gaps[x].second = gap;
            }
        }

        int ans = 1e9;
        for (int i = 1; i <= k; i++) {
            ans = min(max(gaps[i].first / 2, gaps[i].second), ans);
        }

        cout << ans << nl;
    }

    return 0;
}
