#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

vector<pair<int, int>> al[200005];
 
int dfs(int cur, int parent, int edge) {
    int d = 0;
    for (int i = 0; i < al[cur].size(); i++) {
        if (al[cur][i].first != parent) {
            if (al[cur][i].second > edge) {
                d = max(dfs(al[cur][i].first, cur, al[cur][i].second), d);
            } else {
                d = max(dfs(al[cur][i].first, cur, al[cur][i].second) + 1, d);
            }
        }
    }
    return d;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            al[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            al[u].push_back({v, i});
            al[v].push_back({u, i});
        }
 
        cout << dfs(1, -1, 1e9) << nl;
    }
 
    return 0;
}