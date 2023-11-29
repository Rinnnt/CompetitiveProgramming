#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pll pair<ll, ll>

int n, m;
vector<vector<int>> edges;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (auto x : edges[v]) {
    if (mt[x] == -1 || try_kuhn(mt[x])) {
      mt[x] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<pll> pairs(n);
  vector<ll> nums;
  for (auto &x : pairs) {
    cin >> x.first >> x.second;
    nums.push_back(x.first + x.second);
    nums.push_back(x.first - x.second);
    nums.push_back(x.first * x.second);
  }

  sort(nums.begin(), nums.end());

  m = nums.size();
  edges.assign(n, vector<int>());
  mt.assign(m, -1);
  for (int i = 0; i < n; i++) {
    ll a = pairs[i].first;
    ll b = pairs[i].second;
    int aidx = lower_bound(nums.begin(), nums.end(), a + b) - nums.begin();
    int sidx = lower_bound(nums.begin(), nums.end(), a - b) - nums.begin();
    int midx = lower_bound(nums.begin(), nums.end(), a * b) - nums.begin();
    edges[i].push_back(aidx);
    edges[i].push_back(sidx);
    edges[i].push_back(midx);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    used.assign(n, false);
    if (try_kuhn(i))
      ans++;
  }

  if (ans != n) {
    cout << "impossible" << nl;
  } else {
    for (int i = 0; i < n; i++) {
      ll a = pairs[i].first;
      ll b = pairs[i].second;
      int aidx = lower_bound(nums.begin(), nums.end(), a + b) - nums.begin();
      int sidx = lower_bound(nums.begin(), nums.end(), a - b) - nums.begin();
      int midx = lower_bound(nums.begin(), nums.end(), a * b) - nums.begin();
      if (mt[aidx] == i) {
        cout << a << " + " << b << " = " << a + b << nl;
      } else if (mt[sidx] == i) {
        cout << a << " - " << b << " = " << a - b << nl;
      } else if (mt[midx] == i) {
        cout << a << " * " << b << " = " << a * b << nl;
      }
    }
  }

  return 0;
}
