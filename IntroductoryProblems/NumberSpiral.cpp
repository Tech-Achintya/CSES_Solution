#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        if (x < y) {
            if (y % 2 == 0) {
                cout << (y - 1) * (y - 1) + x;
            } else {
                cout << y * y - x + 1;
            }
        } else {
            if (x % 2 == 0) {
                cout << x * x - y + 1;
            } else {
                cout << (x - 1) * (x - 1) + y;
            }
        }
        cout << '\n';
    }
}