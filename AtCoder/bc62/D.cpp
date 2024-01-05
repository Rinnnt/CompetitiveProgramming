#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int a[300001];
ll maxn[100001];
ll minn[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < 3 * n; i++) cin >> a[i];

  ll sum = 0;
  priority_queue<int> maxs;
  for (int i = 0; i < 2 * n; i++) {
    maxs.push(-a[i]);
    sum += a[i];
    if (maxs.size() > n) {
      sum -= -maxs.top();
      maxs.pop();
    }
    if (i >= n - 1) {
      maxn[i - n + 1] = sum;
    }
  }

  sum = 0;
  priority_queue<int> mins;
  for (int i = 3 * n - 1; i >= n; i--) {
    mins.push(a[i]);
    sum += a[i];
    if (mins.size() > n) {
      sum -= mins.top();
      mins.pop();
    }
    if (i <= 2 * n) {
      minn[i - n] = sum;
    }
  }

  ll ans = -1e18;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, maxn[i] - minn[i]);
  }

  cout << ans << nl;

  return 0;
}

