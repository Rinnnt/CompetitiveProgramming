#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

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
        idxs.insert(-pq.top().second);
        pq.pop();
      }

      ans[q.second] = as[*(next(idxs.begin(), p - 1))];
    }


    for (auto a : ans)
      cout << a << nl;

    return 0;
}
