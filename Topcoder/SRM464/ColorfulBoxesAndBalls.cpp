#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class ColorfulBoxesAndBalls {
public:
  int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
    int score = 0;
    if (2 * bothColors > onlyRed + onlyBlue) {
      int both = min(numRed, numBlue);
      score += 2 * both * bothColors;
      score += onlyRed * (numRed - both);
      score += onlyBlue * (numBlue - both);
    } else {
      score += onlyRed * numRed;
      score += onlyBlue * numBlue;
    }
    return score;
  }
};