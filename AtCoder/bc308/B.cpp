#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<string> ate(n);
    for (int i = 0; i < n; i++) {
      cin >> ate[i];
    }

    vector<string> d(m);
    vector<ll> p(m+1);
    map<string, ll> price;
    for (int i = 0; i < m; i++) {
      cin >> d[i];
    }
    for (int i = 0; i < m + 1; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
      price[d[i]] = p[i + 1];
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
      if (price.count(ate[i])) {
        result += price[ate[i]];
      } else {
        result += p[0];
      }
    }

    cout << result;

    return 0;
}
