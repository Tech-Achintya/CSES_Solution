#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<int>> dp(501, vector<int>(501, 1e9));

    for (int a = 1; a <= 500; a++) {
        for (int b = 1; b <= 500; b++) {

            if (a == b) {
                dp[a][b] = 0;
                continue;
            }

            // Horizontal cuts
            for (int k = 1; k < a; k++) {
                dp[a][b] = min(dp[a][b],
                               1 + dp[k][b] + dp[a-k][b]);
            }

            // Vertical cuts
            for (int k = 1; k < b; k++) {
                dp[a][b] = min(dp[a][b],
                               1 + dp[a][k] + dp[a][b-k]);
            }
        }
    }

    cout << dp[A][B] << '\n';
}