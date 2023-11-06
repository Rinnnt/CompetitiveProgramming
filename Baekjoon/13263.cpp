#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define nl '\n'

ll a[100001];
ll b[100001];
ll dp[100001];

ld intersectX(int i, int j) {
  return ((ld)dp[j] - dp[i]) / ((ld)b[i] - b[j]);

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    cin >> b[i];

  deque<int> d;
  d.push_back(0);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    while (d.size() >= 2 && b[d[0]] * a[i] + dp[d[0]] >= b[d[1]] * a[i] + dp[d[1]])
      d.pop_front();

    dp[i] = b[d[0]] * a[i] + dp[d[0]];

    while (d.size() >= 2 && intersectX(i, d.back()) <= intersectX(d[d.size() - 2], d.back()))
      d.pop_back();
    d.push_back(i);
  }

  cout << dp[n - 1];

  return 0;
}
