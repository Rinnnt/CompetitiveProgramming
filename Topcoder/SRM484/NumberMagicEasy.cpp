#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class NumberMagicEasy {
public:
  int theNumber(string answer) {
    string c[] = {
      "YYYYYYYYNNNNNNNN",
      "YYYYNNNNYYYYNNNN", 
      "YYNNYYNNYYNNYYNN",
      "YNYNYNYNYNYNYNYN"
    };
    for (int i = 0; i < 16; i++) {
      string temp = "";
      for (int j = 0; j < 4; j++) {
        temp += c[j][i];
      }
      if (answer == temp) {
        return i + 1;
      }
    }
    return 0;
  }
};