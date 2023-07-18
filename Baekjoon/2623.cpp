#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int idx;
bool possible = true;
bool entered[1001];
bool exited[1001];
int sorted[1001];
vector<int> edges[1001];

void topological_sort(int c) {
  entered[c] = true;
  for (auto x : edges[c]) {
    if (entered[x]) {
      if (!exited[x]) {
        possible = false;
        return;
      }
    } else {
      topological_sort(x);
      if (!possible) {
        return;
      }
    }
  }
  exited[c] = true;
  sorted[idx--] = c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  idx = n;

  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    int prev;
    cin >> prev;
    for (int i = 0; i < p - 1; i++) {
      int next;
      cin >> next;
      edges[prev].push_back(next);
      prev = next;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!entered[i]) {
      topological_sort(i);
      if (!possible) {
        break;
      }
    }
  }

  if (possible) {
    for (int i = 1; i <= n; i++) {
      cout << sorted[i] << nl;
    }
  } else {
    cout << 0;
  }

  return 0;
}
