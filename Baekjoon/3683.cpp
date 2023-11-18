#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

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

  int t;
  cin >> t;
  while (t--) {
    int c, d, v;
    cin >> c >> d >> v;

    vector<pair<string, string>> cats;
    vector<pair<string, string>> dogs;
    for (int i = 0; i < v; i++) {
      string a, b;
      cin >> a >> b;
      if (a[0] == 'C')
        cats.push_back({a, b});
      else
        dogs.push_back({a, b});
    }

    edges.assign(cats.size(), vector<int>());
    mt.assign(dogs.size(), -1);

    for (int i = 0; i < cats.size(); i++)
      for (int j = 0; j < dogs.size(); j++)
        if (cats[i].first == dogs[j].second
            || cats[i].second == dogs[j].first)
          edges[i].push_back(j);

    int ans = 0;
    for (int i = 0; i < cats.size(); i++) {
      used.assign(cats.size(), false);
      if (try_kuhn(i))
        ans++;
    }

    cout << v - ans << nl;
  }

  return 0;
}
