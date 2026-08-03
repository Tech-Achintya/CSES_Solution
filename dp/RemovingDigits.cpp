#include <bits/stdc++.h>
using namespace std;
bool ifContains(long long n,int i){
    while(n>0){
        int digit = n%10;
        if(digit==i){
            return true;
        }
        n=n/10;
    }
    return false;
}


long long solve(long long n,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return 1e9;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long minCost = 1e9;
    for(int i=1;i<=9;i++){
        if(ifContains(n,i)){
            minCost = min(minCost,1+solve(n-i,dp));
        }
    }
    return dp[n] = minCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n,dp);
    return 0;
}
