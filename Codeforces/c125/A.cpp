#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int q = n / 3;
    int r = n % 3;

    if (r > 1) q++;
    int f = q / 12;
    int i = q % 12;

    cout << f << " " << i << nl;

    return 0;
}
