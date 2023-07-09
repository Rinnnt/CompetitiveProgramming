#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<string> a(N + 1);
  map<string, int> m;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    m.insert({a[i], i});
  }
  for (int i = 0; i < M; i++) {
    string x;
    cin >> x;
    if (isalpha(x[0])) {
      cout << m[x] << nl;
    } else {
      cout << a[atoi(x.c_str())] << nl;
    }
  }

}
