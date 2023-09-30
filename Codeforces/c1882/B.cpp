#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a;
        vector<vector<int>> f(51, vector<int>());
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            vector<int> b(k);
            for (auto &x : b) {
                cin >> x;
                f[x].push_back(i);
            }
            a.push_back(b);
        }

        int ans = -1;
        for (int i = 0; i < 51; i++) {
            if (f[i].size() > 0) {
                int tmp = 0;
                for (int j = 0; j < 51; j++) {
                    for (int k = 0; k < f[j].size(); k++) {
                        bool rem = false;
                        for (int l = 0; l < f[i].size(); l++) {
                            if (f[j][k] == f[i][l]) {
                                rem = true;
                            }
                        }
                        if (!rem) {
                            tmp += 1;
                            break;
                        }
                    }
                }
                ans = max(ans, tmp);
            }
        }

        cout << ans << nl;

    }

    return 0;
}
