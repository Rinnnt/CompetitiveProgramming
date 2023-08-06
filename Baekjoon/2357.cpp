#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[100005];
int mins[4 * 100005];
int maxs[4 * 100005];

void buildmins(int idx, int l, int r) {
  if (l == r) {
    mins[idx] = a[l];
    return;
  }
  int m = (l + r) / 2;
  buildmins(idx * 2, l, m);
  buildmins(idx * 2 + 1, m + 1, r);
  mins[idx] = min(mins[idx * 2], mins[idx * 2 + 1]);
}

int querymins(int idx, int l, int r, int ql, int qr) {
  if (ql > qr) {
    return 1e9 + 1;
  }
  if (l == ql && r == qr) {
    return mins[idx];
  }
  int m = (l + r) / 2;
  return min(querymins(idx * 2, l, m, ql, min(m, qr)), querymins(idx * 2 + 1, m + 1, r, max(m + 1, ql), qr));
}

void buildmaxs(int idx, int l, int r) {
  if (l == r) {
    maxs[idx] = a[l];
    return;
  }
  int m = (l + r) / 2;
  buildmaxs(idx * 2, l, m);
  buildmaxs(idx * 2 + 1, m + 1, r);
  maxs[idx] = max(maxs[idx * 2], maxs[idx * 2 + 1]);
}

int querymaxs(int idx, int l, int r, int ql, int qr) {
  if (ql > qr) {
    return 0;
  }
  if (l == ql && r == qr) {
    return maxs[idx];
  }
  int m = (l + r) / 2;
  return max(querymaxs(idx * 2, l, m, ql, min(m, qr)), querymaxs(idx * 2 + 1, m + 1, r, max(m + 1, ql), qr));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  buildmins(1, 1, n);
  buildmaxs(1, 1, n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << querymins(1, 1, n, a, b) << " " << querymaxs(1, 1, n, a, b) << nl;
  }
  
  return 0;
}
