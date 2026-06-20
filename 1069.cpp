#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    int maxCount = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            count = 1;
        }
        maxCount = max(maxCount, count);
    }
    cout << maxCount << '\n';
}