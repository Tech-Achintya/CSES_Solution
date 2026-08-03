#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }   
    vector<vector<bool>> visited (n,vector<bool> (m,false));
    vector<vector<char>> previousDirection(n,vector<char> (m,0));
    vector<char> direction = {'U','R','D','L'};
    vector<int> deltaRow = {-1,0,1,0};
    vector<int> deltaCol = {0,1,0,-1};
    pair<int, int> start, end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                start = {i,j};
            }else if(grid[i][j]=='B'){
                end = {i,j};
            }
        }
    }
    queue<pair<int,int>> q;
    visited[start.first][start.second] = true;
    q.push(start);
    bool found = false;
    while(!q.empty() && !found){
        auto [row,col] = q.front();
        q.pop();
        for(int d = 0;d<4;d++){
            int newRow = deltaRow[d]+row;
            int newCol = deltaCol[d]+col;
            if( (newRow>=0 && newCol>=0 && newRow<n && newCol<m) && !visited[newRow][newCol] && grid[newRow][newCol]!='#'){
                visited[newRow][newCol]=true;
                previousDirection[newRow][newCol] = direction[d];
                q.push({newRow,newCol});
                if(make_pair(newRow,newCol)==end){
                    found=true;
                    break;
                }
            }
        }
    }
    if(!visited[end.first][end.second]){
        cout<<"NO"<<'\n';
        return 0;
    }
    string s;
    pair<int,int> current = end;
    while(current!=start){
            char dir = previousDirection[current.first][current.second];
            s.push_back(dir);
            int index = find(direction.begin(),direction.end(),dir) - direction.begin();
            current.first-= deltaRow[index];
            current.second-= deltaCol[index];
    }
    reverse(s.begin(),s.end());
    cout<<"YES\n";
    cout<<s.size()<<"\n";
    cout<<s<<"\n";
    return 0;
}
