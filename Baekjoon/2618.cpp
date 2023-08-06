#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, w;
pair<int, int> cases[1001];
int memo[1001][1001];
vector<int> cs;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int c1, int c2) {
  if (c1 == w || c2 == w) {
    return 0;
  }

  if (memo[c1][c2]) {
    return memo[c1][c2];
  }

  int nextcase = max(c1, c2) + 1;
  int dist1, dist2;
  if (c1 == 0) {
    dist1 = dist(1, 1, cases[nextcase].first, cases[nextcase].second);
  } else {
    dist1 = dist(cases[c1].first, cases[c1].second, cases[nextcase].first, cases[nextcase].second);
  }

  if (c2 == 0) {
    dist2 = dist(n, n, cases[nextcase].first, cases[nextcase].second);
  } else {
    dist2 = dist(cases[c2].first, cases[c2].second, cases[nextcase].first, cases[nextcase].second);
  }

  int result1 = dist1 + solve(nextcase, c2);
  int result2 = dist2 + solve(c1, nextcase);
  return memo[c1][c2] = min(result1, result2);
}

void route(int c1, int c2, int left) {
  if (c1 == w || c2 == w) {
    return;
  }

  int nextcase = max(c1, c2) + 1;
  int dist1, dist2;
  if (c1 == 0) {
    dist1 = dist(1, 1, cases[nextcase].first, cases[nextcase].second);
  } else {
    dist1 = dist(cases[c1].first, cases[c1].second, cases[nextcase].first, cases[nextcase].second);
  }

  if (c2 == 0) {
    dist2 = dist(n, n, cases[nextcase].first, cases[nextcase].second);
  } else {
    dist2 = dist(cases[c2].first, cases[c2].second, cases[nextcase].first, cases[nextcase].second);
  }

  int result1 = dist1 + solve(nextcase, c2);
  int result2 = dist2 + solve(c1, nextcase);
  if (result1 == left) {
    cout << 1 << nl;
    route(nextcase, c2, left - dist1);
  } else {
    cout << 2 << nl;
    route(c1, nextcase, left - dist2);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= w; i++) {
    cin >> cases[i].first >> cases[i].second;
  }

  int ans = solve(0, 0);
  cout << ans << nl;
  route(0, 0, ans);

  return 0;
}
