#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int nums[200001];
int t[4 * 200001];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    t[ti] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(2 * ti + 1, tl, mid);
  build(2 * ti + 2, mid + 1, tr);
  t[ti] = t[2 * ti + 1] + t[2 * ti + 2];
}

void update(int ti, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    t[ti]++;
    return;
  }

  int mid = (tl + tr) / 2;
  if (i <= mid)
    update(2 * ti + 1, tl, mid, i);
  else
    update(2 * ti + 2, mid + 1, tr, i);
  t[ti] = t[2 * ti + 1] + t[2 * ti + 2];
}

int query(int ti, int tl, int tr, int k) {
  if (tl == tr) {
    return tl;
  }

  int ans;
  int mid = (tl + tr) / 2;
  if (k <= t[2 * ti + 1])
    ans = query(2 * ti + 1, tl, mid, k);
  else
    ans = query(2 * ti + 2, mid + 1, tr, k - t[2 * ti + 1]);
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++) {
      cin >> as[i];
      pq.push({as[i], -i});
    }

    build(0, 0, n - 1);

    int m;
    cin >> m;
    vector<pair<pii, int>> qs(m);
    for (int i = 0; i < m; i++) {
      cin >> qs[i].first.first >> qs[i].first.second;
      qs[i].second = i;
    }

    sort(qs.begin(), qs.end());

    vector<int> ans(m);
    set<int> idxs;
    for (auto q : qs) {
      int k = q.first.first;
      int p = q.first.second;
      while (idxs.size() < k) {
        int idx = -pq.top().second;
        idxs.insert(idx);
        update(0, 0, n - 1, idx);
        pq.pop();
      }

      ans[q.second] = as[query(0, 0, n - 1, p)];
    }


    for (auto a : ans)
      cout << a << nl;

    return 0;
}
