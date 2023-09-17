#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

int n;
ll edges[17][17];
ll dp[100001];
bool selected[17];

ll dfs(int state, int e) {
    if (e == n / 2) {
        return 0;
    }

    if (dp[state]) {
        return dp[state];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!selected[i] && !selected[j]) {
                selected[i] = true;
                selected[j] = true;
                ans = max(ans, edges[i][j] + dfs((state | 1 << (i - 1) | 1 << (j - 1)), e + 1));
                selected[i] = false;
                selected[j] = false;
            }
        }
    }
    return dp[state] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> edges[i][j];
        }
        selected[i] = false;
    }
    selected[n] = false;

    cout << dfs(0, 0);

    return 0;
}
