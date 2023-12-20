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

  ll n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> monsters(n);
  for (auto &x : monsters)
    cin >> x.first >> x.second;
  sort(monsters.begin(), monsters.end());

  ll damage = 0;
  ll bombs_used = 0;
  deque<pair<ll, ll>> bombs;
  for (auto x : monsters) {
    while (!bombs.empty() && abs(x.first - bombs.front().first) > d) {
      damage -= bombs.front().second;
      bombs.pop_front();
    }

    x.second -= damage;
    if (x.second > 0) {
      ll bombs_needed = (x.second + a - 1) / a;
      bombs.push_back({x.first + d, bombs_needed * a});
      bombs_used += bombs_needed;
      damage += bombs.back().second;
    }
  }

  cout << bombs_used << nl;

  return 0;
}

