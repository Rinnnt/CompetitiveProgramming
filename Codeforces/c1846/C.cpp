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
        ll n, m, h;
        cin >> n >> m >> h;
        vector<int> times(m);
        for (int j = 0; j < m; j++) {
            cin >> times[j];
        }
        sort(times.begin(), times.end());
        ll sum = 0;
        ll rpenalty = 0;
        ll rscore = 0;
        ll id = 0;
        while (id < times.size() && sum < h) {
            sum += times[id];
            if (sum <= h) {
                rscore++;
                rpenalty += sum;
            }
            id++;
        }
        ll rank = 1;
        for (int i = 0; i < n - 1; i++) {
            vector<int> times(m);
            for (int j = 0; j < m; j++) {
                cin >> times[j];
            }
            sort(times.begin(), times.end());
            ll sum = 0;
            ll penalty = 0;
            ll score = 0;
            ll id = 0;
            while (id < times.size() && sum < h) {
                sum += times[id];
                if (sum <= h) {
                    score++;
                    penalty += sum;
                }
                id++;
            }
            if (score > rscore || (score == rscore && penalty < rpenalty)) {
                rank++;
            }
        }
        cout << rank << nl;

    }

    return 0;
}
