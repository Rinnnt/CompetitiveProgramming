#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

int nums[500001];
int parent[500001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < 500001; i++)
    nums[i] = -1, parent[i] = -1;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    nums[a] = b;
  }

  int ans = 1;
  int last = 0;
  vector<int> dp;
  dp.push_back(-1);
  for (int i = 0; i < 500001; i++) {
    int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
    if (idx == dp.size()) {
      dp.push_back(nums[i]);
      ans++;
      last = nums[i];
    } else {
      dp[idx] = nums[i];
    }
    if (nums[i] > 0)
      parent[nums[i]] = dp[idx - 1];
  }

  cout << n - (ans - 1) << nl;

  stack<int> stk;
  stk.push(last);
  while (parent[stk.top()] != -1)
    stk.push(parent[stk.top()]);

  for (int i = 0; i < 500001; i++) {
    if (nums[i] != -1) {
      if (!stk.empty()) {
        if (nums[i] != stk.top())
          cout << i << nl;
        else
          stk.pop();
      } else {
        cout << i << nl;
      }
    }
  }

  return 0;
}
