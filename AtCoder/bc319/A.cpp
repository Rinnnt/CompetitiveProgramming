#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

map<string, int> rating;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rating["tourist"] = 3858;
    rating["ksun48"] = 3679;
    rating["Benq"] = 3658;
    rating["Um_nik"] = 3648;
    rating["apiad"] = 3638;
    rating["Stonefeang"] = 3630;
    rating["ecnerwala"] = 3613;
    rating["mnbvmar"] = 3555;
    rating["newbiedmy"] = 3516;
    rating["semiexp"] = 3481;

    string s;
    cin >> s;
    cout << rating[s];

    return 0;
}
