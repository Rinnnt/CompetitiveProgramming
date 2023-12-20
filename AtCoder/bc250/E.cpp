#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int a[200001];
int b[200001];
int size_a[200001];
int size_b[200001];
vector<int> new_a;
vector<int> new_b;
int diff[200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  set<int> a_set;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a_set.insert(a[i]);
    size_a[i] = a_set.size();
    if (size_a[i] > size_a[i - 1])
      new_a.push_back(a[i]);
  }

  set<int> b_set;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b_set.insert(b[i]);
    size_b[i] = b_set.size();
    if (size_b[i] > size_b[i - 1])
      new_b.push_back(b[i]);
  }

  set<int> diff_set;
  int k = min(size_a[n], size_b[n]);
  for (int i = 1; i <= k; i++) {
    for (auto new_c : {new_a[i - 1], new_b[i - 1]}) {
      if (diff_set.count(new_c)) {
        diff_set.erase(new_c);
      } else {
        diff_set.insert(new_c);
      }
    }
    diff[i] = diff_set.size();
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    string ans = "Yes";
    if (size_a[x] != size_b[y]) {
      ans = "No";
    } else {
      if (diff[size_a[x]]) {
        ans = "No";
      }
    }
    cout << ans << nl;
  }

  return 0;
}

