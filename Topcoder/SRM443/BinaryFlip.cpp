#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class BinaryFlips {
public:
  int minimalMoves(int A, int B, int K) {
    for (ll i = 0; i <= A + B; i++) {
      long long rest = i * K - A;
      long long use = ((i / 2) * B + ((i - 1) / 2) * A) * 2;
      if(rest >= 0 && rest % 2 == 0 && rest <= use) {
        return (int)i;
      }
    }
    return -1;
  }
};