#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

struct node {
  bool end = false;
  int children = 0;
  map<char, int> to;
};

vector<node> t;

void insert(string s) {
  int cur = 0;
  for (auto c : s) {
    if (t[cur].to.count(c)) {
      cur = t[cur].to[c];
    } else {
      int cursize = t.size();
      t[cur].to[c] = cursize;
      t[cur].children++;
      cur = cursize;
      t.push_back(node());
    }
  }
  t[cur].end = true;
}

bool firstCanWin(int cur) {
  for (auto n : t[cur].to)
    if (!firstCanWin(n.second))
      return true;

  return false;
}

bool firstCanLose(int cur) {
  if (t[cur].children == 0)
    return true;

  for (auto n : t[cur].to)
    if (!firstCanLose(n.second))
      return true;

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  t.push_back(node());

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s);
  }

  if (firstCanWin(0)) {
    if (firstCanLose(0)) {
      cout << "First" << nl;
    } else {
      cout << (k % 2 ? "First" : "Second") << nl;
    }
  } else {
    cout << "Second" << nl;
  }

  return 0;
}
