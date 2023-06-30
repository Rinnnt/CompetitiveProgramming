#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class InterestingParty {
  public:
  int bestInvitation(vector<string> first, vector<string> second) {
    map<string, int> m;
    for (int i = 0; i < first.size(); i++) {
      m[first[i]]++;
      m[second[i]]++;
    }

    int ans = 0;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
      if (it->second > ans) {
        ans = it->second;
      }
    }
    return ans;
  }
};