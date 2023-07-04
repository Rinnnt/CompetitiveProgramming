#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class AutoLoan {
public:
  bool leftOver(double price, double monthylPayment, int loanTerm, double rate) {
    for (int i = 0; i < loanTerm; i++) {
      price *= 1 + (rate / 1200);
      price -= monthylPayment;
    }
    return price > 0;
  }

  double interestRate(double price, double monthlyPayment, int loanTerm) {
    double l = 0;
    double r = 100;
    while (r - l > 1e-9) {
      double rate = (r + l) / 2;
      if (leftOver(price, monthlyPayment, loanTerm, rate)) {
        r = rate;
      } else {
        l = rate;
      }
    }
    return (r + l) / 2;
  }
};