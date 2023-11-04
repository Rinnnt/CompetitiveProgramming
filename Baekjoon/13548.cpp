#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

const int block_size = 300;

struct Query {
  int l, r, idx;
  bool operator<(Query other) const {
    return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
  }
};

int a[100001];
int c[100001]; // count of some number
int cc[100001]; // count of (counts of some number)
int maxc = 0; // cur max count of some number

void remove(int idx) {
  cc[c[a[idx]]]--;
  c[a[idx]]--;
  cc[c[a[idx]]]++;
  if (!cc[maxc])
    maxc = c[a[idx]];
}

void add(int idx) {
  cc[c[a[idx]]]--;
  c[a[idx]]++;
  cc[c[a[idx]]]++;
  if (c[a[idx]] > maxc)
    maxc = c[a[idx]];
}

int get_answer() {
  return maxc;
}

vector<int> mo_s_algorithm(vector<Query> queries) {
  vector<int> answers(queries.size());
  sort(queries.begin(), queries.end());

  // initialise data structures
  for (int i = 0; i < 100001; i++)
    c[i] = 0;

  int cur_l = 0;
  int cur_r = -1;
  for (Query q : queries) {
    while (cur_l > q.l)
      add(--cur_l);
    while (cur_r < q.r)
      add(++cur_r);
    while (cur_l < q.l)
      remove(cur_l++);
    while (cur_r > q.r)
      remove(cur_r--);
    answers[q.idx] = get_answer();
  }
  return answers;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int m;
  cin >> m;
  vector<Query> queries;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    Query q;
    q.l = --l; q.r = --r; q.idx = i;
    queries.push_back(q);
  }

  for (auto x : mo_s_algorithm(queries))
    cout << x << nl;

  return 0;
}
