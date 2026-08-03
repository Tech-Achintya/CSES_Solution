#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(200001,vector<int>(2,-1));
int dfs(int node,int canInclude,vector<vector<int>> &adjList,int par){
    if(dp[node][canInclude]!=-1){
        return dp[node][canInclude];
    }

    if(canInclude==1){
        int res = 0;
        for(int neigh : adjList[node]){
            if(neigh!=par){
                res += dfs(neigh,1,adjList,node);
            }
        }
        int ans = 0;
        for(int neigh:adjList[node]){
            if(neigh!=par){
                ans = max(ans,res-dp[neigh][1]+1+dfs(neigh,0,adjList,node));
            }
        }
        return dp[node][canInclude] = ans;
    }else{
        int ans = 0;
        for(int neigh : adjList[node]){
            if(neigh!=par){
                int a = dfs(neigh,1,adjList,node);
                ans += max(a,dfs(neigh,0,adjList,node));
            }
        }
        return dp[node][canInclude]=ans;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<< max(dfs(1,1,adjList,-1),dfs(1,0,adjList,-1));
    return 0;
}