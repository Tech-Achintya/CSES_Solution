#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int solve(vector<int>& a, vector<int>& b, int n, bool startFlip) {
    int cnt = startFlip ? 1 : 0;
    bool justBeforeIncreased = startFlip;
    for(int i=0;i<n-1;i++){
        int ai = (a[i] + (justBeforeIncreased?1:0))%2;
        if((ai+a[i+1])%2!=b[i]){
            justBeforeIncreased = true;
            cnt++;
        }else{
            justBeforeIncreased = false;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n-1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n-1; i++) {
            cin >> b[i];
        }
        int cnt = min(solve(a,b,n,false), solve(a,b,n,true));
        cout<<cnt<<"\n";
    }
}