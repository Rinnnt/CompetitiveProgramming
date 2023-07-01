#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[51];
class  CorporationSalary {
public:
  ll calculateSalary(vector<string> relations, int i) {
    if (relations[i].find('Y') != string::npos) {
      return 1;
    }
    if (dp[i] != 0) {
      return dp[i];
    }
    for (int j = 0; j < relations[i].size(); j++) {
      if (relations[i][j] == 'Y') {
        dp[i] += calculateSalary(relations, j);
      }
    }
    return dp[i];
  }

  ll totalSalary(vector<string> relations) {
    ll res = 0;
    for (int i = 0; i < relations.size(); i++) {
      res += calculateSalary(relations, i);
    }
    return res;
  }
};