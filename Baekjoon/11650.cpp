#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end(), cmp);
  for (auto x : p) {
    cout << x.first << " " << x.second << nl;
  }
}
