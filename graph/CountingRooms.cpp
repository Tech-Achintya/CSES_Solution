#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &visited) {
    int n = mat.size();
    int m = mat[0].size();

    // boundary check + already visited check
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1 || mat[i][j] == '#')
        return;

    visited[i][j] = 1;

    dfs(i - 1, j, mat, visited);
    dfs(i + 1, j, mat, visited);
    dfs(i, j - 1, mat, visited);
    dfs(i, j + 1, mat, visited);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> visited(n,vector<int>(m,-1));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.' && visited[i][j]==-1){
                count++;
                dfs(i,j,mat,visited);
            }
        }
    }
    cout<<count<<"\n";
}

