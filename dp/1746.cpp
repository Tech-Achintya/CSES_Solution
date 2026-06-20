#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
vector<vector<int>> dp;
int funct(int index,int prev,vector<int> &arr , int n,int m){
    if(index==n)
        return 1;
    
    if(dp[index][prev]!=-1){
        return dp[index][prev];
    }
        
    int  ans = 0;
    if(arr[index]!=0){
        int num = abs(arr[index]-prev);
        if(num<=1){
            ans = funct(index+1,arr[index],arr,n,m);
        }
    }else{
        for(int i=prev-1;i<=prev+1;i++){
            if(i>0 && i<=m){
                ans+=funct(index+1,i,arr,n,m);
                ans%=mod;
            }
        }
    }
    return dp[index][prev] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i =0;i<n;i++){  
        cin>>arr[i];
    }
    // dp.resize(n+1,vector<int> (m+1,-1));
    // int result = 0;
    // //handling arr[0]=0 seperately'
    // if(arr[0]==0){
    //     for(int i=1;i<=m;i++){
    //         result+=funct(1,i,arr,n,m);
    //         result%=mod;
    //     }
    // }else{
    //     result = funct(1,arr[0],arr,n,m);
    // }
    //Tabulation
    dp.resize(n+1,vector<int> (m+1,0));


    //Base Case
    for(int i=0;i<=m;i++){
        dp[n][i] = 1;
    }
    for(int idx=n-1;idx>=1;idx--){
        for(int prev = 1;prev<=m;prev++){
            int ans = 0;
            if(arr[idx]!=0){
                if(abs(arr[idx]-prev)<=1){
                    ans = dp[idx+1][arr[idx]];
                }
            }else{
                for(int val = prev-1;val<=prev+1;val++){
                    if(val>=1 && val<=m){
                        ans+= dp[idx+1][val];
                        ans%=mod;
                    }
                }
            }
            dp[idx][prev] = ans;
        }
    }
    //handling the 0 index case
    int result = 0;
    if(arr[0]==0){
        for(int i=1;i<=m;i++){
            result += dp[1][i];
            result%=mod;    
        }
    }else{
        result = dp[1][arr[0]];
    }
    cout<<result;
}