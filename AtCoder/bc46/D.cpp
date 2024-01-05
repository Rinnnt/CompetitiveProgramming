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
  stack<char> st;
  for (auto c : s) {
    if (!st.empty() && st.top() != c)
      st.pop();
    else
      st.push(c);
  }

  if (st.empty()) {
    cout << 0 << nl;
  } else {
    if (st.top() == 'g') {
      cout << st.size() / 2 << nl;
    } else {
      cout << (st.size() + 1) / 2;
    }
  }

  return 0;
}

