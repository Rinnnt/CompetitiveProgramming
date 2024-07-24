#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n, k;
int as[1005][1005];
vector<int> dp[1005];

vector<int> combine(vector<int> as, vector<int> bs) {
  vector<int> res;
  int aidx = 0;
  int bidx = 0;
  int asize = as.size();
  int bsize = bs.size();
  for (int i = 0; i < k; i++) {
    if (aidx >= asize && bidx >= bsize) {
      break;
    } else if (aidx < asize && bidx < bsize) {
      if (as[aidx] < bs[bidx]) {
        res.push_back(bs[bidx++]);
      } else {
        res.push_back(as[aidx++]);
      }
    } else if (aidx >= asize) {
      res.push_back(bs[bidx++]);
    } else if (bidx >= bsize) {
      res.push_back(as[aidx++]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {

    cin >> n >> k;

    dp[0] = vector<int>(1, 0);
    dp[1] = vector<int>(1, 0);
    for (int i = 1; i <= n; i++) {
      dp[i + 1].clear();
      for (int j = i; j <= n; j++) {
        cin >> as[i][j];
      }
    }

    for (int i = 1; i <= n; i++) {
      vector<int> ns;
      priority_queue<pii> q;
      q.push({dp[i][0], i});
      vector<int> idxs(n + 1, 0);
      for (int j = 1; j <= i; j++) {
        q.push({dp[j - 2 + 1][idxs[j - 2 + 1]] + as[j][i], j - 2 + 1});
      }
      for (int z = 0; z < k; z++) {
        if (q.empty()) break;

        int s = q.top().first;
        int idx = q.top().second;
        q.pop();
        ns.push_back(s);
        if (idx == i) {
          if (++idxs[idx] < dp[idx].size())
            q.push({dp[idx][idxs[idx]], idx});
        } else {
          if (++idxs[idx] < dp[idx].size())
            q.push({dp[idx][idxs[idx]] + as[idx + 1][i], idx});
        }
      }
      dp[i + 1] = ns;
    }

    for (auto x : dp[n + 1])
      cout << x << " ";
    cout << nl;
  }

  return 0;
}
