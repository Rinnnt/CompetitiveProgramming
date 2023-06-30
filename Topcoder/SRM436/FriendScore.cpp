
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class FriendScore {
public:
  int highestScore(vector<string> friends) {
    int res = 0;
    for (int i = 0; i < friends.size(); i++) {
      vector<int> fs;
      for (int j = 0; j < friends[i].size(); j++) {
        if (friends[i][j] == 'Y') {
          fs.push_back(j);
        }
      }
      set<int> all;
      for (int j = 0; j < fs.size(); j++) {
        all.insert(fs[j]);
        for (int k = 0; k < friends[fs[j]].size(); k++) {
          if (k != i && friends[fs[j]][k] == 'Y') {
            all.insert(k);
          }
        }
      }
      res = max((int)all.size(), res);
    }
    return res;
  }
};