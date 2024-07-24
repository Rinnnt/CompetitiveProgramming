#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int solve(vector<int> vs) {
  int res = vs[0] ^ vs[1];
  vector<int> st;
  for (auto v : vs) {
    while (!st.empty() && st.back() < v) st.pop_back();
    st.push_back(v);
    if (st.size() >= 2) res = max(res, st.back() ^ st[st.size() - 2]);
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> vs(n);
    for (auto &v : vs) cin >> v;
    vector<int> rvs = vs;
    reverse(rvs.begin(), rvs.end());
    cout << max(solve(vs), solve(rvs)) << nl;

    return 0;
}
