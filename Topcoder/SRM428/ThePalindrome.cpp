#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class ThePalindrome {
public:
  int find(string s) {
    int i = 0;
    int n = s.size();
    while (i < n) {
      bool palin = true;
      for (int j = 0; j < (n - i) / 2; j++) {
        if (s[i + j] != s[n - j - 1]) {
          palin = false;
          break;
        }
      }
      if (palin) {
        break;
      }
      i++;
    }

    return n + i;
  }
};