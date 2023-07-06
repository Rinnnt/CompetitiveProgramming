#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool comp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<pair<int, int>> l;
      for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        l.push_back({a, b});
      }
      sort(l.begin(), l.end(), comp);

      ll score = 0;
      queue<int> on;
      int i = 0;
      while (i < n) {
        score += l[i].second;
        on.push(l[i].first);
        i++;
        int non = on.size();
        while (i < n && non >= l[i].first) {
          i++;
        }
        while (!on.empty() && non >= on.front()) {
          on.pop();
        }
      }
      cout << score << nl;
    }

    return 0;
}

