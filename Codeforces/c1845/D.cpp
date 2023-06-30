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
        map<ll, ll> scores;
        scores.insert({-1e17, 0});

        ll max = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;

            if (a < 0) {
                if (scores[-1e17] >= max) {
                    max = scores[-1e17];
                    scores.insert({max, max});
                }
            }
            map<ll, ll>::iterator it;
            for (it = scores.begin(); it != scores.end(); it++) {
                it->second += a;
                if (it->second < it->first) {
                    it->second = it->first;
                }
            }
        }

        map<ll, ll>::iterator it;
        ll result = -1;
        ll maxscore = -1;
        for (it = scores.begin(); it != scores.end(); it++) {
            if (it->second > maxscore) {
                maxscore = it->second;
                result = it->first;
            }
        }

        cout << result << nl;
    }

    return 0;
}
