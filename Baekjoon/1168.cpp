#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int nums[100001];
int t[4 * 100001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 1;
    return;
  }

  int mid = (tl + tr) / 2;
  build(ti * 2 + 1, tl, mid);
  build(ti * 2 + 2, mid + 1, tr);
  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
}

int query(int ti, int tl, int tr, int x) {
  if (tl == tr) {
    t[ti]--;
    return tl;
  }

  int ans;
  int mid = (tl + tr) / 2;
  if (x <= t[ti * 2 + 1])
    ans = query(ti * 2 + 1, tl, mid, x);
  else
    ans = query(ti * 2 + 2, mid + 1, tr, x - t[ti * 2 + 1]);

  t[ti] = t[ti * 2 + 1] + t[ti * 2 + 2];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  build(0, 1, n);
  cout << "<";
  int prev = 1;
  for (int i = 0; i < n; i++) {
    int pos = (prev + k - 1) % (n - i);
    if (pos == 0) pos = n - i;
    cout << query(0, 1, n, pos) << (i < n - 1 ? ", " : "");
    prev = pos;
  }
  cout << ">" << nl;

  return 0;
}

