#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int funct(int i,int j,string s,string t){
    //base case
    if(j==t.size()){
        return s.size()-i;
    }
    if(i==s.size()){
        return t.size()-j;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans4 = 1e9;
    if(s[i]==t[j]){
        ans4 = funct(i+1,j+1,s,t);
    }
    //case 1: add the current char of t in s
    int ans1 = 1 + funct(i,j+1,s,t);
    // case 2: delete
    int ans2 = 1 + funct(i+1,j,s,t);
    // case 3 : replace
    int ans3 = 1 + funct(i+1,j+1,s,t);
 
    return dp[i][j] = min({ans1,ans2,ans3,ans4});
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    dp.resize(n+1,vector<int> (m+1,0));
    // int ans = funct(0,0,s,t);
    for(int i=0;i<=n;i++){
        dp[i][m] = n-i;
    }
    for(int j=0;j<=m;j++){
        dp[n][j] = m-j;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int ans4 = 1e9;
            if(s[i]==t[j]){
                ans4 = dp[i+1][j+1];
            }
            //case 1: add the current char of t in s
            int ans1 = 1 + dp[i][j+1];
            // case 2: delete
            int ans2 = 1 + dp[i+1][j];
            // case 3 : replace
            int ans3 = 1 + dp[i+1][j+1];
         
            dp[i][j] = min({ans1,ans2,ans3,ans4}); 
        }
    }
    cout<<dp[0][0]<<"\n";
}
