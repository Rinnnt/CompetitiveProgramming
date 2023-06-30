#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class InterestingDigits {
public:
  vector<int> digits(int base) {
    vector<int> d;
    for (int i = 2; i <= base - 1; i++) {
      if ((base - 1) % i == 0) {
        d.push_back(i);
      }
    }
    return d;
  }
};