#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int n, m;
int nums[10];
int current[10];
bool chosen[10];

void dfs(int idx) {
  if (idx == m) {
    for (int i = 0; i < m; i++) {
      cout << current[i] << " ";
    }
    cout << nl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!chosen[i]) {
      chosen[i] = true;
      current[idx] = nums[i];
      dfs(idx + 1);
      chosen[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    chosen[i] = false;
  }

  sort(nums, nums + n);

  dfs(0);

  return 0;
}
