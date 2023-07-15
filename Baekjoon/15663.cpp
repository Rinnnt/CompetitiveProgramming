#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
map<int, int> f;
int chosen[10];

void solve(int idx) {
  if (idx == m) {
    for (int i = 0; i < m; i++) {
      cout << chosen[i] << " ";
    }
    cout << nl;
    return;
  }
  for (auto it = f.begin(); it != f.end(); it++) {
    if (it->second > 0) {
      it->second--;
      chosen[idx] = it->first;
      solve(idx + 1);
      it->second++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[x]++;
  }

  solve(0);

  return 0;
}
