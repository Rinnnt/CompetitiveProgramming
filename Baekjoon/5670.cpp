#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

struct node {
  bool isword;
  int nexts;
  int next[26];

  node () {
    isword = false;
    nexts = 0;
    for (int i = 0; i < 26; i++) {
      next[i] = -1;
    }
  }
};

vector<node> trie;

void add(string s) {
  int v = 0;
  for (auto c : s) {
    int index = c - 'a';
    if (trie[v].next[index] == -1) {
      trie[v].next[index] = trie.size();
      trie[v].nexts += 1;
      trie.push_back(node());
    }
    v = trie[v].next[index];
  }
  trie[v].isword = true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  while (cin >> n) {
    trie.clear();
    trie.push_back(node());

    vector<string> words;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      words.push_back(s);
      add(s);
    }

    int total = 0;
    for (string s : words) {
      int p = 0;
      int i = 0;
      int v = 0;
      while (i < s.size()) {
        p += 1;
        v = trie[v].next[s[i++] - 'a'];
        while (!trie[v].isword && trie[v].nexts == 1) {
          v = trie[v].next[s[i++] - 'a'];
        }
      }
      total += p;
    }

    cout << fixed << setprecision(2) << ((double)total) / n << nl;
  }


  return 0;
}

