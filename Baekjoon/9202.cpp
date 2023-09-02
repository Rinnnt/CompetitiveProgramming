#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

string board[4];
bool visited[4][4];

bool within(int x, int y) {
  return x >= 0 && x < 4 && y >= 0 && y < 4;
}

struct node {
  int to[26];
  string word;
  bool output;
  int seen;

  node() {
    output = false;
    word = "";
    for (int i = 0; i < 26; i++) {
      to[i] = - 1;
    }
    seen = 0;
  }
};

vector<node> trie;

void add(string x) {
  int idx = 0;
  for (int i = 0; i < x.size(); i++) {
    if (trie[idx].to[x[i] - 'A'] == -1) {
      trie[idx].to[x[i] - 'A'] = trie.size();
      trie.push_back(node());
      trie[trie[idx].to[x[i] - 'A']].word = trie[idx].word + x[i];
    }
    idx = trie[idx].to[x[i] - 'A'];
  }
  trie[idx].output = true;
}

int score = 0;
string longest = "";
int longestlen = 0;
int numwords = 0;
int cur = 0;

int scores[10] = {
  0, 0, 0, 1, 1, 2, 3, 5, 11, 0
};

vector<pair<int, int>> dxys = {
  {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

void dfs(int x, int y, int idx) {
  if (trie[idx].to[board[x][y] - 'A'] == -1) {
    return;
  }
  int nidx = trie[idx].to[board[x][y] - 'A'];
  if (trie[nidx].output && trie[nidx].seen != cur) {
    int len = trie[nidx].word.size();
    score += scores[len];
    if (len > longestlen || (len == longestlen && trie[nidx].word < longest)) {
      longestlen = len;
      longest = trie[nidx].word;
    }
    numwords++;
    trie[nidx].seen = cur;
  }

  for (auto dxy : dxys) {
    int nx = x + dxy.first;
    int ny = y + dxy.second;
    if (within(nx, ny) && !visited[nx][ny]) {
      visited[nx][ny] = true;
      dfs(nx, ny, nidx);
      visited[nx][ny] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int w;
  cin >> w;
  trie.push_back(node());

  for (int i = 0; i < w; i++) {
    string s;
    cin >> s;
    add(s);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      visited[i][j] = false;
    }
  }

  int n;
  cin >> n;
  for (int c = 1; c <= n; c++) {
    cur = c;
    for (auto &x : board) {
      cin >> x;
    }
    score = 0;
    longestlen = 0;
    longest = "";
    numwords = 0;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        visited[i][j] = true;
        dfs(i, j, 0);
        visited[i][j] = false;
      }
    }
    cout << score << " " << longest << " " << numwords << nl;
  }

  return 0;
}
