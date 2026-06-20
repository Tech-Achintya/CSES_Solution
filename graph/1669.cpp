#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> parent;
vector<bool> visited;
int cycleStart = -1;
int cycleEnd = -1; 

bool dfs(int node,int parentNode){
    visited[node] = true;
    for(auto it: adjList[node]){
        if(it==parentNode) continue;
        if(!visited[it]){
            parent[it] = node;
            if(dfs(it,node)) return true;
        }else{
            cycleStart = it;
            cycleEnd = node;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u; cin>>u;
        int v; cin>>v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    adjList = graph;
    visited.resize(n+1,false);
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        if(!visited[i] && dfs(i,-1)) break;
    }
    if(cycleStart==-1){
        cout<<"IMPOSSIBLE"<<"\n";
    }else{
        vector<int> cycle;
        int curr = cycleEnd;
        cycle.push_back(cycleStart);
        while(curr!=cycleStart){
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(cycleStart);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<"\n";
        for(int node : cycle){
            cout<<node<<" ";
        }
    }
}