#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

using ll = long long;

vector<int> edges[200005];
bool wormhole[200005];
int d_from_s[200005];
int d_to_e[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 200005; i++) {
        edges[i].clear();
        d_from_s[i] = 1e9;
        d_to_e[i] = 1e9;
    }

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> wormholes(k);
    for (int i = 0; i < k; i++) {
        cin >> wormholes[i];
        wormhole[wormholes[i]] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    d_from_s[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : edges[cur]) {
            if (d_from_s[x] > d_from_s[cur] + 1) {
                d_from_s[x] = d_from_s[cur] + 1;
                q.push(x);
            }
        }
    }

    ll d_wormholes_to_e = 0;

    q.push(n);
    d_to_e[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        if (wormhole[cur]) {
            d_wormholes_to_e += d_to_e[cur];
        }
        q.pop();
        for (auto x : edges[cur]) {
            if (d_to_e[x] > d_to_e[cur] + 1) {
                d_to_e[x] = d_to_e[cur] + 1;
                q.push(x);
            }
        }
    }

    ll numerator = d_to_e[1];
    ll denominator = 1;

    for (auto x : wormholes) {
        ll den = k - 1;
        ll num = ((ll)d_from_s[x]) * den + (d_wormholes_to_e - d_to_e[x]);
        if (num * denominator < numerator * den) {
            numerator = num;
            denominator = den;
        }
    }

    ll g = __gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << numerator << "/" << denominator << nl;

    return 0;
}
