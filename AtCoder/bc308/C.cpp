#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool compare(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b) {
  return (a.first.first * (b.first.first + b.first.second) > b.first.first * (a.first.first + a.first.second))
      || (a.first.first * (b.first.first + b.first.second) == b.first.first * (a.first.first + a.first.second) && a.second < b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<pair<pair<ll, ll>, int>> rate(n);
    for (int i = 0; i < n; i++) {
      ll a, b;
      cin >> a >> b;
      rate[i] = make_pair(make_pair(a, b), i + 1);
    }

    sort(rate.begin(), rate.end(), compare);

    for (int i = 0; i < n; i++) {
      cout << rate[i].second << " ";
    }

    return 0;
}
