#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'
#define pii pair<int, int>

int n;
int t[16][1 << 15];

void copy_l(int k, int i, int pi) {
  t[k][i] = 2 * t[k - 1][pi];

  if (2 * pi < (1 << (k - 1))) {
    t[k][i]++;
    copy_l(k, 2 * i, 2 * pi);
    copy_l(k, 2 * i + 1, 2 * pi + 1);
  }
}

void copy_r(int k, int i, int pi) {
  t[k][i] = 2 * t[k - 1][pi];

  if (2 * pi < (1 << (k - 1))) {
    copy_r(k, 2 * i, 2 * pi);
    copy_r(k, 2 * i + 1, 2 * pi + 1);
  } else {
    t[k][i]++;
  }
}

void preorder(int c) {
  cout << t[n][c] << " ";
  int left = 2 * c;
  if (left < (1 << n)) {
    preorder(left);
    preorder(left + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  t[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    t[i][1] = 1;
    copy_l(i, 2, 1);
    copy_r(i, 3, 1);
  }

  preorder(1);
  cout << nl;

  return 0;
}

