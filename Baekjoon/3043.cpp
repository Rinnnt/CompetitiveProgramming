#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<pii> xs(n);
  vector<pii> ys(n);
  for (int i = 0; i < n; i++) {
    xs[i].second = ys[i].second = i + 1;
    cin >> ys[i].first >> xs[i].first;
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  vector<string> ans;
  for (int i = 0; i < n; i++)
    if (xs[i].first > i + 1)
      for (int k = 0; k < xs[i].first - (i + 1); k++)
        ans.push_back(to_string(xs[i].second) + " L");
  for (int i = n - 1; i >= 0; i--)
    if (xs[i].first < i + 1)
      for (int k = 0; k < i + 1 - xs[i].first; k++)
        ans.push_back(to_string(xs[i].second) + " R");

  for (int i = 0; i < n; i++)
    if (ys[i].first > i + 1)
      for (int k = 0; k < ys[i].first - (i + 1); k++)
        ans.push_back(to_string(ys[i].second) + " U");
  for (int i = n - 1; i >= 0; i--)
    if (ys[i].first < i + 1)
      for (int k = 0; k < i + 1 - ys[i].first; k++)
        ans.push_back(to_string(ys[i].second) + " D");

  cout << ans.size() << nl;
  for (auto x : ans)
    cout << x << nl;

  return 0;
}

