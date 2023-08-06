#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int lis[1000001];
int a[1000001];
int dp[1000001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int maxlen = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int idx = lower_bound(lis, lis + maxlen, a[i]) - lis;
    dp[i] = idx;
    lis[idx] = a[i];
    if (idx == maxlen) {
      maxlen++;
    }
  }

  cout << maxlen << nl;
  deque<int> s;
  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] == maxlen - 1) {
      s.push_back(a[i]);
      maxlen--;
    }
  }
  while (!s.empty()) {
    cout << s.back() << " ";
    s.pop_back();
  }

  return 0;
}
