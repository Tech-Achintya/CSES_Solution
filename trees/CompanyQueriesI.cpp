#include <bits/stdc++.h>
using namespace std;
int MAX = 20;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> table(MAX,vector<int> (n+1,0));
    // fill the parent
    for(int i=2;i<=n;i++){
        cin>>table[0][i];
    }
    table[0][1] = 0; 
    for(int i=1;i<MAX;i++){
        for(int j=1;j<=n;j++){
            if(table[i-1][j]==0){
                table[i][j] = 0;
                continue;
            }
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    while(q--){
        int node,k;
        cin>>node>>k;
        for(int i=0;i<MAX;i++){
            if(k & (1<<i)){
                node = table[i][node];
                if(node==0) break;
            }
        }
        int ans = node==0?-1:node;
        cout<<ans<<"\n";
    }
}