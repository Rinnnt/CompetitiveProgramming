#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

struct node {
  int val;
  struct node *prev;
  struct node *next;

  node() {
    val = 0;
    prev = NULL;
    next = NULL;
  }
};

void remove(struct node *p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
}

void insert_before(struct node *p, struct node *o) {
  p->prev = o->prev;
  p->next = o;

  p->prev->next = p;
  p->next->prev = p;
}

void insert_after(struct node *p, struct node *o) {
  p->next = o->next;
  p->prev = o;

  p->prev->next = p;
  p->next->prev = p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<struct node> pnodes(n + 2, node());
  vector<struct node *> nodes(n + 2);
  for (int i = 0; i < n + 2; i++)
    nodes[i] = &pnodes[i];
  nodes[0]->next = nodes[1];
  nodes[n + 1]->prev = nodes[n];
  for (int i = 1; i < n + 1; i++) {
    nodes[i]->val = i;
    nodes[i]->prev = nodes[i - 1];
    nodes[i]->next = nodes[i + 1];
  }

  for (int i = 0; i < m; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    remove(nodes[a]);
    if (c == 'A')
      insert_before(nodes[a], nodes[b]);
    else
      insert_after(nodes[a], nodes[b]);
  }

  vector<int> values;
  struct node *p = nodes[0];

  while (p->next != nodes[n + 1]) {
    p = p->next;
    values.push_back(p->val);
  }

  vector<int> lis;
  vector<int> parent(n + 1);
  int nlis = 0;
  for (auto x : values) {
    int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
    if (idx == nlis) {
      lis.push_back(x);
      nlis++;
    } else {
      lis[idx] = x;
    }
    parent[x] = idx == 0 ? -1 : lis[idx - 1];
  }

  cout << n - nlis << nl;
  int v = lis[nlis - 1];
  vector<int> rlis(nlis);
  while (v != -1) {
    rlis[--nlis] = v;
    v = parent[v];
  }

  int j = 1;
  for (int i = 0; i < rlis.size(); i++) {
    while (j < rlis[i])
      cout << "A " << j++ << " " << rlis[i] << nl;
    j++;
  }

  int k = n;
  while (k >= j)
    cout << "B " << k-- << " " << j - 1 << nl;

  return 0;
}

