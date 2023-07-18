#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int want[100001];
int group[100001];
int pos[100001];
int cycles;

void dfs(int c) {
  if (group[want[c]] == -1) {
    group[want[c]] = group[c];
    pos[want[c]] = pos[c] + 1;
    dfs(want[c]);
  } else if (group[want[c]] == group[c]) {
    cycles += pos[c] - pos[want[c]] + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> want[i];
      group[i] = -1;
      pos[i] = -1;
    }
    cycles = 0;

    for (int i = 1; i <= n; i++) {
      if (group[i] == -1) {
        group[i] = i;
        pos[i] = 1;
        dfs(i);
      }
    }

    cout << n - cycles << nl;
  }

  return 0;
}
