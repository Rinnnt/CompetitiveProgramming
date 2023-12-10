#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<pair<string, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  vector<int> ans(n, 0);
  for (int i = 0; i < n - 1; i++) {
    int idx = 0;
    while (idx < a[i].first.size()
        && idx < a[i + 1].first.size()
        && a[i].first[idx] == a[i + 1].first[idx])
      idx++;
    ans[a[i].second] = max(ans[a[i].second], idx);
    ans[a[i + 1].second] = max(ans[a[i + 1].second], idx);
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << nl;

  return 0;
}

