#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int parent[51];
int s[51];

void make_set(int v) {
  parent[v] = v;
  s[v] = 1;
}

int find_set(int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (s[a] < s[b]) {
      swap(a, b);
    }
    parent[b] = a;
    s[a] += s[b];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    make_set(i);
  }

  int k;
  cin >> k;
  vector<int> knows(k);
  for (int i = 0; i < k; i++) {
    cin >> knows[i];
  }

  vector<vector<int>> parties(m);
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c;
    vector<int> members(c);
    int prev = -1;
    for (int j = 0; j < c; j++) {
      cin >> members[j];
      if (prev != -1) {
        union_set(prev, members[j]);
      }
      prev = members[j];
    }
    parties[i] = members;
  }

  set<int> known;
  for (auto x : knows) {
    known.insert(find_set(x));
  }

  int ans = 0;
  for (auto party : parties) {
    bool possible = true;
    for (auto member : party) {
      if (known.count(find_set(member))) {
        possible = false;
        break;
      }
    }
    if (possible) {
      ans++;
    }
  }

  cout << ans;

  return 0;
}
