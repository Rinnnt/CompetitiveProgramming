#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

struct P {
  ll x, y;
};

vector<P> v;

ll ccw(P a, P b, P c) {
  ll abdx = b.x - a.x;
  ll abdy = b.y - a.y;
  ll acdx = c.x - a.x;
  ll acdy = c.y - a.y;

  ll cross = abdx * acdy - abdy * acdx;
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

  int tt;
  cin >> tt;
  while (tt--) {
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

    P f1, f2;
    P temp;
    temp.x = 0;
    temp.y = 0;
    ll maxdist = 0;
    int j = 1;
    for (int i = 0; i < st.size(); i++) {
      int i_next = (i + 1) % st.size();

      while (true) {
        int j_next = (j + 1) % st.size();

        P di, dj;
        di.x = st[i_next].x - st[i].x;
        di.y = st[i_next].y - st[i].y;
        dj.x = st[j_next].x - st[j].x;
        dj.y = st[j_next].y - st[j].y;

        if (ccw(temp, di, dj) < 0) {
          j = j_next;
        } else {
          break;
        }
      }

      if ((st[i].x-st[j].x)*(st[i].x-st[j].x) + (st[i].y-st[j].y)*(st[i].y-st[j].y) > maxdist) {
        maxdist = (st[i].x-st[j].x)*(st[i].x-st[j].x) + (st[i].y-st[j].y)*(st[i].y-st[j].y);
        f1 = st[i];
        f2 = st[j];
      }
    }

    cout << f1.x << " " << f1.y << " " << f2.x << " " << f2.y << nl;

  }

  return 0;
}
