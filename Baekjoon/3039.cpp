#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n, m;
struct student {
  int a, b;
  int sorted_index;
  int index;
};

bool pair_cmp(const student &X, const student &Y) {
  if (X.b != Y.b) return X.b < Y.b;
  return X.a < Y.a;
}

bool index_cmp(const student &X, const student &Y) {
  return X.index < Y.index;
}

struct event {
  int who, type;
};

student S[200000];
event E[200000];
int t[4 * 200000];

inline int merge(int s1, int s2) {
  if (s1 == -1) return s2;
  if (s2 == -1) return s1;
  if (S[s1].a < S[s2].a) return s2;
  return s1;
}

void update(int ti, int tl, int tr, int i, int s) {
  if (tl == tr && tl == i) {
    t[ti] = s;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i, s);
  else
    update(2 * ti + 2, mid + 1, tr, i, s);
  t[ti] = merge(t[2 * ti + 1], t[2 * ti + 2]);
}

int query(int ti, int tl, int tr, int l, int r, int minA) {
  if (l > r || t[ti] == -1 || S[t[ti]].a < minA)
    return -1;

  if (tl == tr)
    return t[ti];

  int mid = (tl + tr) / 2;
  int t = query(2 * ti + 1, tl, mid, l, min(r, mid), minA);
  if (t != -1) return t;
  return query(2 * ti + 2, mid + 1, r, max(l, mid + 1), r, minA);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  m = 0;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'D') {
      cin >> S[m].a >> S[m].b;
      S[m].index = m;
      E[i].who = m++;
      E[i].type = 1;
    } else {
      cin >> E[i].who;
      E[i].who--;
      E[i].type = 2;
    }
  }
 
  sort(S, S + m, pair_cmp);
  for (int i = 0; i < m; i++) S[i].sorted_index = i;
  sort(S, S + m, index_cmp);

  memset(t, -1, sizeof t);
  for (int i = 0; i < n; i++) {
    if (E[i].type == 1) {
      update(0, 0, m - 1, S[E[i].who].sorted_index, E[i].who);
    } else {
      int x = query(0, 0, m - 1, S[E[i].who].sorted_index + 1, m - 1, S[E[i].who].a);
      if (x == -1)
        cout << "NE" << nl;
      else
        cout << x + 1 << nl;
    }
  }

  return 0;
}

