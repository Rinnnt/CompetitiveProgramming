#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        vector<string> board(3);
        for (int i = 0; i < 3; i++) {
            cin >> board[i];
        }

        char winner = '#';
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != '.') {
                winner = board[i][0];
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != '.') {
                winner = board[0][i];
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != '.') {
            winner = board[0][0];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != '.') {
            winner = board[0][2];
        }
        if (winner != '#') {
            cout << winner << nl;
        } else {
            cout << "DRAW" << nl;
        }
    }

    return 0;
}
