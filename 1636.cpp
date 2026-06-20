#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long mod = 1e9+7;
ll solve(ll N, ll X, vector<ll>& coins){
    vector<ll> dp(X + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= X; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }
    return dp[X];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,x,arr)<<"\n";
}