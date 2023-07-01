#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class BatchSystem {
public:
  vector<int> schedule(vector<int> duration, vector<string> user) {
    int N = duration.size();

    map<string, ll> jobTime;
    for (int n = 0; n < N; n++) {
      jobTime[user[n]] += duration[n];
    }

    vector<bool> done(N);
    vector<int> ans;
    while (ans.size() < N) {
      string next;
      for (int n = 0; n < N; n++) {
        if (!done[n] && (next.empty() || jobTime[user[n]] < jobTime[next])) {
          next = user[n];
        }
      }

      for (int n = 0; n < N; n++) {
        if (user[n] == next) {
          done[n] = true;
          ans.push_back(n);
        }
      }
    }
    return ans;
  }
};