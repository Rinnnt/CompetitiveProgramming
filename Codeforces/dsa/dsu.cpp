#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define MAXN 254001

int parent[MAXN];
int setsize[MAXN];

void make_set(int v) {
  parent[v] = v;
  setsize[v] = 1;
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
    if (setsize[a] < setsize[b]) {
      swap(a, b);
    }
    parent[b] = a;
    setsize[a] += setsize[b];
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {

    }

    return 0;
}

