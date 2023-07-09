#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool cmp(string a, string b) {
  if (a.size() < b.size()) {
    return true;
  } 
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < b[i]) {
        return true;
      }else if (a[i] > b[i]) {
        return false;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<string> a;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (!s.count(x)) {
      a.push_back(x);
    }
    s.insert(x);
  }

  sort(a.begin(), a.end(), cmp);
  for (auto x : a) {
    cout << x << nl;
  }

}
