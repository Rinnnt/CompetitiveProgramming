#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> meds(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> meds[i].first >> meds[i].second;
      sum += meds[i].second;
    }

    sort(meds.begin(), meds.end());

    ll idx = 0;
    ll days = 1;
    while (sum > k) {
      sum -= meds[idx].second;
      days = meds[idx].first + 1;
      idx++;
    }

    cout << days << nl;

    return 0;
}
