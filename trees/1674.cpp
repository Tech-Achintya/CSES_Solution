#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, int parent, vector<int> &sub){
    sub[node] = 1;
    for(int neigh : adjList[node]){
        if(neigh == parent) continue;
        dfs(neigh, adjList, node, sub);
        sub[node] += sub[neigh];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> adjList(n + 1);
    for(int i = 2; i <= n; i++){
        adjList[i].push_back(arr[i]);
        adjList[arr[i]].push_back(i);
    }
    vector<int> sub(n + 1);
    dfs(1, adjList, -1, sub);
    for(int i = 1; i <= n; i++){
        cout << sub[i]-1 << " ";
    }
}