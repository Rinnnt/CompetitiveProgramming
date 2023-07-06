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
        ll n;
        cin >> n;
        map<int, int> run;
        map<int, int> run2;
        int cur = -1;
        int currun = 0;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (cur == -1 || cur != x) {
                if (cur != -1) {
                    run[cur] = max(run[cur], currun);
                }
                cur = x;
                currun = 1;
            } else if (cur == x) {
                currun += 1;
            }
        }
        run[cur] = max(run[cur], currun);
        cur = -1;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (cur == -1 || cur != x) {
                if (cur != -1) {
                    run2[cur] = max(run2[cur], currun);
                }
                cur = x;
                currun = 1;
            } else if (cur == x) {
                currun += 1;
            }
        }
        run2[cur] = max(run2[cur], currun);
        int ans = 0;
        map<int, int>::iterator it;
        for (it = run.begin(); it != run.end(); it++) {
            ans = max(it->second + run2[it->first], ans);
        }
        for (it = run2.begin(); it != run2.end(); it++) {
            ans = max(it->second + run[it->first], ans);
        }
        cout << ans << nl;
    }

    return 0;
}
