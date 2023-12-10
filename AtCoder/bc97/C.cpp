#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;
  int k;
  cin >> k;

  set<string> st;
  for (int len = 1; len <= k; len++) {
    for (int i = 0; i < s.size() - len + 1; i++) {
      st.insert(s.substr(i, len));
    }
  }

  auto it = st.begin();
  for (int i = 0; i < k - 1; i++)
    it++;

  cout << *it << nl;

  return 0;
}

