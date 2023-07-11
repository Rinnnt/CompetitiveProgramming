#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  set<string> heard;
  set<string> seen;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    heard.insert(s);
  }
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    seen.insert(s);
  }

  vector<string> both;
  for (auto s : seen) {
    if (heard.count(s)) {
      both.push_back(s);
    }
  }
  cout << both.size() << nl;
  for (auto x : both) {
    cout << x << nl;
  }


}
