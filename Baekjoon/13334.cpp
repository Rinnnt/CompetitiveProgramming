#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
    if (x.first > x.second) {
      swap(x.first, x.second);
    }
  }
  sort(a.begin(), a.end(), cmp);
  ll d;
  cin >> d;
  ll ans = 0;
  ll pqlen = 0;
  priority_queue<int, vector<int>, greater<int>> ls;
  for (int i = 0; i < n; i++) {
    if (a[i].second - a[i].first > d) {
      continue;
    }
    ll cur = a[i].second;
    ls.push(a[i].first);
    pqlen++;
    while (pqlen > 0 && ls.top() < cur - d) {
      ls.pop();
      pqlen--;
    }
    ans = max(ans, pqlen);
  }


  cout << ans;

  return 0;
}
