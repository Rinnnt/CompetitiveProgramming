#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<int> mixer[200001];
ll dp[200001];
bool visited[200001];

void solve(int cur) {
    visited[cur] = true;
    if (!mixer[cur].empty()) {
        ll mixc = 0;
        for (auto x : mixer[cur]) {
            if (!visited[x]) {
                solve(x);
            }
            mixc += dp[x];
        }
        if (mixc < dp[cur]) {
            dp[cur] = mixc;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> dp[i];
            mixer[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            dp[x] = 0;
        }

        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int e;
                cin >> e;
                mixer[i].push_back(e);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                solve(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << nl;
    }

    return 0;
}
