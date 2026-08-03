#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int j = 0;

    for (int k = 1; k <= n; k++) {
        while (j < n && s[j] != 'x')
            j++;

        if (j == n)
            cout << n << "\n";
        else {
            cout << j + 1 << "\n";
            j++;
        }
    }

    return 0;
}