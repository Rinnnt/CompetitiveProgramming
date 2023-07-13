#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int t[26][2];

void preorder(int cur) {
  if (cur >= 0) {
    cout << (char)('A' + cur);
    preorder(t[cur][0]);
    preorder(t[cur][1]);
  }
}

void inorder(int cur) {
  if (cur >= 0) {
    inorder(t[cur][0]);
    cout << (char)('A' + cur);
    inorder(t[cur][1]);
  }
}

void postorder(int cur) {
  if (cur >= 0) {
    postorder(t[cur][0]);
    postorder(t[cur][1]);
    cout << (char)('A' + cur);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string n, l, r;
    cin >> n >> l >> r;
    t[n[0] - 'A'][0] = l[0] - 'A';
    t[n[0] - 'A'][1] = r[0] - 'A';
  }

  preorder(0);
  cout << nl;
  inorder(0);
  cout << nl;
  postorder(0);

  return 0;
}
