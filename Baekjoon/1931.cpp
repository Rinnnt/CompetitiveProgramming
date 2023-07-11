#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

priority_queue<int, vector<int>, greater<int>> min_heap;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> times(N);
  for (int i = 0; i < N; i++) {
    cin >> times[i].first >> times[i].second;
  }

  sort(times.begin(), times.end(), cmp);

  int free = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (times[i].first >= free) {
      ans++;
      free = times[i].second;
    }
  }

  cout << ans << nl;
}
