#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(1e6+1,vector<int>(1e6+1,-1));
int mod = 1e9+7;
int funct(int i,int sum,int val){
    if(sum==val){
        return 1;
    }
    if(sum>val){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int way1 = funct(i,sum+i,val)%mod;
    int way2 = 0;
    if(i+1<=val){
        way2 = funct(i+1,sum+i,val)%mod;
    }
    return dp[i][sum] = (way1 + way2)%mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<funct(1,0,n);    
}