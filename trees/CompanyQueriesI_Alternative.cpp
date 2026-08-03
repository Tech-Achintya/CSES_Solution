#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 200005;
const long long LOG = 20;

long long up[MAXN][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }

    up[1][0] = 0; // root has no parent

    // Precompute 2^j ancestors
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j-1] != 0)
                up[i][j] = up[ up[i][j-1] ][j-1];
            else
                up[i][j] = 0;
        }
    }

    // Process queries
    while (q--) {
        int node, k;
        cin >> node >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == 0) break;
            }
        }

        if (node == 0)
            cout << -1 << "\n";
        else
            cout << node << "\n";
    }

    return 0;
}
