#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

string s;
bool used[8];
set<string> perms;
int n;

void add_perms(string cur) {
  if (cur.size() == n) {
    perms.insert(cur);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = true;
      cur += s[i];
      add_perms(cur);
      cur.erase(cur.size() - 1, 1);
      used[i] = false;
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    for (int i = 0; i < 8; i++) {
      used[i] = false;
    }
    add_perms("");
    cout << perms.size() << nl;
    for (auto x : perms) {
      cout << x << nl;
    }

    return 0;
}