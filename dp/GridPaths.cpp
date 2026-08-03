#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
vector<vector<long long>> dp;
long long dfs(int i,int j,vector<vector<char>> &grid,int n){
    if(i>=n || j>=n){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long path1 = 0;
    long long path2 = 0;
    if(i+1<n && grid[i+1][j]!='*'){
        path1 = dfs(i+1,j,grid,n);
    }
    if(j+1<n && grid[i][j+1]!='*'){
        path2 = dfs(i,j+1,grid,n);
    }
    return dp[i][j] = (path1+path2)%mod;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
        cout<<0;
        return 0;
    }
    dp.resize(n,vector<long long>(n,-1));
    cout<<dfs(0,0,grid,n);;
}