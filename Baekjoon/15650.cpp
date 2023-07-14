#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
int chosen[10];
void subsets(int cur, int idx) {
  if (idx == m) {
    for (int i = 0; i < m; i++) {
      cout << chosen[i] << " ";
    }
    cout << nl;
    return;
  }
  for (int i = cur; i <= n; i++) {
    chosen[idx] = i;
    subsets(i + 1, idx + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  subsets(1, 0);

  return 0;
}
