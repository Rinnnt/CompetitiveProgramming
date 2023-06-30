#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class Cryptography {
public:
  ll encrypt(vector<int> numbers) {
    ll ans = 1;
    sort(numbers.begin(), numbers.end());
    numbers[0]++;
    for (int i = 0; i < numbers.size(); i++) {
      ans *= numbers[i];
    }
    return ans;
  }
};