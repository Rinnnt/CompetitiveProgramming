#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool power_two(int x) {
    return (x & (x - 1)) == 0;
}

int find_greatest(int x) {
    for (int i = 0; i < 1000; i++) {
        if (((x >> i) & 1) == 1) {
            return (1 << i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int k = x;
        vector<int> a;
        while (!power_two(x)) {
            int divisor = find_greatest(x);
            a.push_back(divisor);
            x -= divisor;
        }
        while (x != 1) {
            int divisor = x / 2;
            a.push_back(divisor);
            x -= divisor;
        }
        cout << a.size() + 1 << nl;
        cout << k;
        for (auto x : a) {
            k -= x;
            cout << " " << k;
        }
        cout << nl;
    }

    return 0;
}
