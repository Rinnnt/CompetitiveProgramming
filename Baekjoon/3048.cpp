#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define nl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n1, n2;
  cin >> n1 >> n2;
  string a, b;
  cin >> a >> b;
  int t;
  cin >> t;

  char l[n1 + n2];

  for (int i = 0; i < n1; i++) {
    int aidx = n1 - i - 1;
    l[min(aidx + n2, aidx + max(0, t - i))] = a[i];
  }

  for (int i = 0; i < n2; i++) {
    int bidx = i + n1;
    l[max(i, bidx - max(0, t - i))] = b[i];
  }

  for (int i = 0; i < n1 + n2; i++)
    cout << l[i];
  cout << nl;

  return 0;
}

/*
// 0
CBA
    DEF

// 1
CB A
  D EF

// 2
C B A
 D E F

// 3
 C B A
D E F

// 4
  C BA
DE F

// 5
   CBA
DEF 

// 0
ALJ
   CRUO
// 1
AL J
  C RUO
// 2
A L J
 C R UO
// 3
 A L J
C R U O
// 4
  A L J
CR U O
// 5
   A LJ
CRU O
// 6
    ALJ
CRUO
*/
