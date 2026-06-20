#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++){
        int u; cin>>u;
        int v; cin>>v;
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }
    vector<bool> visited(n+1,false);
    vector<int> team(n+1,0);

    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            q.push({i,1});
            while(!q.empty()){
                auto currQ = q.front();
                q.pop();
                int currNode = currQ.first;
                int currTeam = currQ.second;
                team[currNode] = currTeam;
                int preferedNeighTeam = currTeam==1?2:1;
                for(auto it : adjList[currNode]){
                    if(!visited[it]){
                        visited[it] = true;
                        team[it] = preferedNeighTeam;
                        q.push({it,preferedNeighTeam});
                    }else{
                        if(team[it]!=preferedNeighTeam){
                            cout<<"IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<team[i]<<" ";
    }

}
