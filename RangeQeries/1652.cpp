#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> grid(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='*'){
                grid[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            grid[i][j] = grid[i][j-1] + grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            grid[j][i] = grid[j-1][i] + grid[j][i];
        }
    }
    while(q--){
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        int part1 = grid[ex-1][ey-1];
        int part2 = 0;
        int part3 = 0;
        int part4 = 0;
        if(sx-1-1>=0){
            part2 = grid[sx-1-1][ey-1];
        }
        if(sy-1-1>=0){
            part3 = grid[ex-1][sy-1-1];
        }
        if(sx-1-1>=0 && sy-1-1>=0){
            part4 = grid[sx-1-1][sy-1-1];
        }
        cout<<part1-part2-part3+part4<<"\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
}