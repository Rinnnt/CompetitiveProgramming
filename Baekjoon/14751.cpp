#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

const ld eps = 0.00000001;

ll x2, x1;

struct Line {
  ll y2, y1;
  int idx;

  bool operator<(const Line &other) {
    return y2 - y1 < other.y2 - other.y1 || (y2 - y1 == other.y2 - other.y1 && y2 > other.y2);
  }
};

struct Query {
  ld x;
  int idx;

  bool operator<(const Query &other) {
    return x < other.x;
  }
};

ld intersectX(Line a, Line b) {
  return ((ld)a.y1 * x2 - a.y2 * x1 - (b.y1 * x2 - b.y2 * x1)) / ((ld)b.y2 - b.y1 - (a.y2 - a.y1));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> x2 >> x1;

  int n;
  cin >> n;

  vector<Line> lines;
  for (int i = 1; i <= n; i++) {
    ll minY, maxY;
    cin >> maxY >> minY;
    maxY = 500001 - maxY;
    minY = 500001 - minY;
    Line l;
    l.y2 = maxY;
    l.y1 = minY;
    l.idx = i;
    lines.push_back(l);
  }

  sort(lines.begin(), lines.end());

  deque<Line> d;
  for (auto l : lines) {
    if (!d.empty() && l.y2 - l.y1 == d.back().y2 - d.back().y1)
      continue;
    while (d.size() >= 2
        && (intersectX(d.back(), l) <= intersectX(d[d.size()-2], d.back())))
      d.pop_back();
    d.push_back(l);
  }

  int m;
  cin >> m;
  vector<Query> qs;
  for (int i = 0; i < m; i++) {
    Query q;
    cin >> q.x;
    q.idx = i;
    qs.push_back(q);
  }

  sort(qs.begin(), qs.end());

  vector<int> ans(qs.size());
  for (auto q : qs) {
    while (d.size() >= 2
        && (q.x * ((d[1].y2 - d[1].y1) - (d[0].y2 - d[0].y1)) >= d[0].y1 * x2 - d[0].y2 * x1 - (d[1].y1 * x2 - d[1].y2 * x1)))
      d.pop_front();
    ans[q.idx] = d[0].idx;
  }

  for (auto x : ans)
    cout << x << nl;

  return 0;
}
