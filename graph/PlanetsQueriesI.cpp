#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


vector<int> parent;
vector<vector<int>> table;
int MAX = 31;
void build(int n){
    table.resize(MAX+1,vector<int> (n+1));
    for(int i=1;i<=n;i++){
        table[0][i] = parent[i];
    }

    for(int i=1;i<MAX;i++){
        for(int j=1;j<=n;j++){
            int par = table[i-1][j];
            table[i][j] = table[i-1][par];
        }
    }
}
int getAncestor(int node,int k){
    int par = node;
    int cnt = 0;
    while(k>0){
        if(k&1){
            par = table[cnt][par];
        }
        k>>=1;
        cnt++;
    }
    return par;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while (t--) {
        int n,q;
        cin >> n >> q;
        parent.resize(n+1);
        for (int i = 0; i < n; i++) {
            int par;cin>>par;
            parent[i+1] = par;
        }
        build(n);
        while(q--){
            int node,k;
            cin>>node>>k;
            int ans = getAncestor(node,k);
            cout<<ans<<"\n";
        }
    }
}