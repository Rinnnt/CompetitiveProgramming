#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int idx;
int sorted[32001];
bool entered[32001];
vector<int> edges[32001];

void topological_sort(int c) {
  for (auto x : edges[c]) {
    if (!entered[x]) {
      entered[x] = true;
      topological_sort(x);
    }
  }
  sorted[idx--] = c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  idx = n - 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!entered[i]) {
      entered[i] = true;
      topological_sort(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << sorted[i] << " ";
  }

  return 0;
}
