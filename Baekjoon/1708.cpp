#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

struct P {
  double x, y;
};

vector<P> v;

ll ccw(P a, P b, P c) {
  ll abdx = b.x - a.x;
  ll abdy = b.y - a.y;
  ll bcdx = c.x - b.x;
  ll bcdy = c.y - b.y;

  ll cross = abdx * bcdy - abdy * bcdx;
  return cross;
}

bool compareCCW(P a, P b) {
  ll cp = ccw(v[0], a, b);
  if (cp == 0) return ((a.x-v[0].x)*(a.x - v[0].x) + (a.y-v[0].y)*(a.y-v[0].y))
    < ((b.x-v[0].x)*(b.x-v[0].x) + (b.y-v[0].y)*(b.y-v[0].y));
  return cp < 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  v.resize(n);
  for (auto &x : v) {
    cin >> x.x >> x.y;
    if (x.y < v[0].y || (x.y == v[0].y && x.x < v[0].x)) {
      swap(v[0], x);
    }
  }

  sort(v.begin() + 1, v.end(), compareCCW);

  vector<P> st;
  for (int i = 0; i < n; i++) {
    while (st.size() > 1 && ccw(st[st.size() - 2], st.back(), v[i]) >= 0) {
      st.pop_back();
    }
    st.push_back(v[i]);
  }

  cout << st.size() << nl;

  return 0;
}
