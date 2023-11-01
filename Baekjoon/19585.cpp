#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

struct node {
  char end;
  map<char, int> next;

  node() {
    end = 0;
  }
};

vector<node> trie;

void add(vector<node> &t, string s, int type) {
  int c = 0;
  for (auto ch : s) {
    if (!t[c].next.count(ch)) {
      t[c].next[ch] = t.size();
      t.push_back(node());
    }
    c = t[c].next[ch];
  }
  t[c].end = t[c].end | type;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  trie.push_back(node());

  int c, n;
  cin >> c >> n;

  for (int i = 0; i < c; i++) {
    string color;
    cin >> color;
    add(trie, color, 1);
  }

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    reverse(name.begin(), name.end());
    add(trie, name, 2);
  }

  int q;
  cin >> q;
  vector<bool> cmatch, nmatch;
  for (int i = 0; i < q; i++) {
    string name;
    cin >> name;
    cmatch.assign(name.size(), false);
    nmatch.assign(name.size(), false);

    int c = 0;
    for (int i = 0; i < name.size(); i++) {
      if (!trie[c].next.count(name[i]))
        break;

      c = trie[c].next[name[i]];
      if ((trie[c].end & 1) == 1)
        cmatch[i] = true;
    }

    c = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
      if (!trie[c].next.count(name[i]))
        break;

      c = trie[c].next[name[i]];
      if ((trie[c].end & 2) == 2)
        nmatch[i] = true;
    }

    bool pos = false;
    for (int i = 0; i < name.size() - 1; i++)
      if (cmatch[i] && nmatch[i + 1])
        pos = true;

    cout << (pos ? "Yes" : "No") << nl;
  }

  return 0;
}

