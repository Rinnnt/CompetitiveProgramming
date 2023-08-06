#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int a[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<ll> s;

  s.push(0);
  ll ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      ll check = a[s.top()];
      s.pop();
      ans = max(ans, check * (i - s.top() - 1));
    }
    s.push(i);
  }

  cout << ans;

  return 0;
}
