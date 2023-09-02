#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool bit(int value, int pos) {
  return (value >> pos) & 1;
}

struct node {
  int next[2];
  int cnt;
  node () {
    next[0] = next[1] = -1;
    cnt = 0;
  }
};

vector<node> trie;

void add(int x) {
  int v = 0;
  for (int i = 29; i >= 0; i--) {
    int b = bit(x, i);
    if (trie[v].next[b] == -1){ 
      trie[v].next[b] = trie.size();
      trie.push_back(node());
    }
    ++trie[v].cnt;
    v = trie[v].next[b];
  }
  ++trie[v].cnt;
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
