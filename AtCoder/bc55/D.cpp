#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int n;
string s;
int status[100005];

int propagate(int status, int adj_status, char ans) {
  if (status == 1) {
    if (ans == 'o') {
      return adj_status;
    } else {
      return -1 * adj_status;
    }
  }
  else if (status == -1) {
    if (ans == 'o') {
      return -1 * adj_status;
    } else {
      return adj_status;
    }
  }
  return 2;
}

bool valid_assign(int first_status, int l_status, int r_status) {
  for (int i = 0; i < 100001; i++) status[i] = 0;

  status[0] = first_status;
  status[1] = l_status;
  status[n - 1] = r_status;
  status[n] = status[0];
  int l = 1;
  int r = n - 1;

  bool valid = true;
  while (l <= r) {
    if (status[l + 1] != 0) {
      if (status[l + 1] != propagate(status[l], status[l - 1], s[l])) {
        valid = false;
      }
    }
    status[l + 1] = propagate(status[l], status[l - 1], s[l]);
    l++;

    if (status[r - 1] != 0) {
      if (status[r - 1] != propagate(status[r], status[r + 1], s[r])) {
        valid = false;
      }
    }
    status[r - 1] = propagate(status[r], status[r + 1], s[r]);
    r--;
  }

  return valid;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  cin >> s;

  vector<pair<int, pii>> checks;
  if (s[0] == 'o') {
    checks.push_back({1, {1, 1}});
    checks.push_back({1, {-1, -1}});
    checks.push_back({-1, {1, -1}});
    checks.push_back({-1, {-1, 1}});
    for (auto check : checks) {
      if (valid_assign(check.first, check.second.first, check.second.second)) {
        for (int i = 0; i < n; i++) {
          cout << (status[i] == 1 ? 'S' : 'W');
        }
        cout << nl;
        return 0;
      }
    }
  } else {
    checks.push_back({1, {1, -1}});
    checks.push_back({1, {-1, 1}});
    checks.push_back({-1, {-1, -1}});
    checks.push_back({-1, {1, 1}});
    for (auto check : checks) {
      if (valid_assign(check.first, check.second.first, check.second.second)) {
        for (int i = 0; i < n; i++) {
          cout << (status[i] == 1 ? 'S' : 'W');
        }
        cout << nl;
        return 0;
      }
    }
  }

  cout << -1 << nl;

  return 0;
}

