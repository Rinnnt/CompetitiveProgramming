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
  vector<int> xs(n);
  vector<pii> sorted_xs;
  vector<int> ys(n);
  vector<pii> sorted_ys;
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i];
    sorted_xs.push_back({xs[i], i});
    sorted_ys.push_back({ys[i], i});
  }
  sort(sorted_xs.begin(), sorted_xs.end());
  sort(sorted_ys.begin(), sorted_ys.end());

  vector<int> xidx(n);
  for (int i = 0; i < n; i++)
    xidx[sorted_xs[i].second] = i;

  vector<int> yidx(n);
  for (int i = 0; i < n; i++)
    yidx[sorted_ys[i].second] = i;

  ll total_weight = 0;
  vector<bool> selected(n, false);
  priority_queue<pii> q;
  q.push({-0, 0});
  while (!q.empty()) {
    int d = -q.top().first;
    int c = q.top().second;
    q.pop();

    if (selected[c]) continue;

    selected[c] = true;
    total_weight += d;

    if (xidx[c] > 0) {
      int l = sorted_xs[xidx[c] - 1].second;
      if (!selected[l])
        q.push({-(abs(xs[c] - xs[l])), l});
    }
    if (xidx[c] < n - 1) {
      int r = sorted_xs[xidx[c] + 1].second;
      if (!selected[r])
        q.push({-(abs(xs[c] - xs[r])), r});
    }
    if (yidx[c] > 0) {
      int b = sorted_ys[yidx[c] - 1].second;
      if (!selected[b])
        q.push({-(abs(ys[c] - ys[b])), b});
    }
    if (yidx[c] < n - 1) {
      int t = sorted_ys[yidx[c] + 1].second;
      if (!selected[t])
        q.push({-(abs(ys[c] - ys[t])), t});
    }
  }

  cout << total_weight << nl;

  return 0;
}

