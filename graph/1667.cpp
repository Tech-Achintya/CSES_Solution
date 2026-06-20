#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adjList(n+1); 
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    queue<int> q;
    vector<int> parent(n+1);
    vector<int> visited(n+1,0);
    q.push(1);
    visited[1] = 1;
    bool found = false;
    while(!q.empty() && !found){
        int node = q.front();
        q.pop();
        for(int adjNode : adjList[node]){
            if(visited[adjNode]!=1){
                parent[adjNode] = node;
                q.push(adjNode);
                visited[adjNode] = 1;
                if(adjNode==n){
                    found = true;
                    break;
                }
            }
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    int currNode = n;
    path.push_back(currNode);
    while(true){
        currNode = parent[currNode];
        path.push_back(currNode);
        if(currNode==1){
            break;
        }
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
}