#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

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

const int mod = 998244353;

ll binpow(int a, int n) {
  ll m = 1;
  ll mult = a;
  while (n) {
    if (n & 1) {
      m *= mult;
      m %= mod;
    }
    mult *= mult;
    mult %= mod;
    n >>= 1;
  }
  return m;
}

ll solve(int idx, int ones) {
  if (trie[idx].next[0] == -1 && trie[idx].next[1] == -1) {
    return (ll(trie[idx].cnt) * ll(trie[idx].cnt) * (ones + 1)) % mod;
  }

  ll ans = 0;
  if (trie[idx].next[0] != -1 && trie[idx].next[1] != -1) {
    ans += ll(trie[trie[idx].next[0]].cnt) * trie[trie[idx].next[1]].cnt * (ones + 1 + (ones % 2));
    ans %= mod;
    ans += ll(trie[trie[idx].next[0]].cnt) * trie[trie[idx].next[1]].cnt * (ones + 1 + (1 - ones % 2));
    ans %= mod;
  }

  if (trie[idx].next[0] != -1) {
    ans += solve(trie[idx].next[0], ones);
    ans %= mod;
  }
  if (trie[idx].next[1] != -1) {
    ans += solve(trie[idx].next[1], ones + 1);
    ans %= mod;
  }

  return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
      trie.clear();
      trie.push_back(node());
      int n;
      cin >> n;
      for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        add(a);
      }

      ll ans = solve(0, 0);
      ll ninv = binpow(n, mod - 2);
      ans *= ninv;
      ans %= mod;
      ans *= ninv;
      ans %= mod;

      cout << ans << nl;
    }


    return 0;
}
