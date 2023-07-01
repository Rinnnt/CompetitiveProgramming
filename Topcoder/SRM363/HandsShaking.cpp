#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll dp[60] = {1, 0, 1, 0, 2};

class HandsShaking {
public:
  ll countPerfect(int n) {
    if (n <= 4) {
      return dp[n];
    }

    if (dp[n] == 0) {
      for (int i = 1; i < n; i += 2) {
        dp[n] += countPerfect(i - 1) * countPerfect(n - i - 1);
      }
    }
    return dp[n];
  }
};