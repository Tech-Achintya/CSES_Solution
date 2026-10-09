#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define ppb pop_back
#define eb emplace_back

#define ff first
#define ss second
#define mp make_pair
#define int  long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()

#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define int long long
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

#define lb lower_bound
#define ub upper_bound

#define pc __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll

#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);

const int MOD=1e9+7;
const int MOD2=998244353;
const ll INF=1e18;

vector<vector<int>> adjList;
vector<int> res;
vector<int> countOfBelowNodes;
ll root_depth = 0;

int dfs(int node,int par,int curr_depth){
    int total_count = 1;
    root_depth+=curr_depth;
    for(auto it : adjList[node]){
        if(it==par) continue;
        total_count += dfs(it,node,curr_depth+1);
    }
    countOfBelowNodes[node] = total_count;
    return total_count;
}

void  DFS(int parent,int prevNode,int n){
    for(auto child : adjList[parent]){
        if(child==prevNode) continue;
        res[child] = res[parent] + n-countOfBelowNodes[child] - countOfBelowNodes[child];
        DFS(child,parent,n);
    }
}

signed main(){
    FAST
    int n;
    cin>>n;
    adjList.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    res.resize(n+1);
    countOfBelowNodes.resize(n+1);
    dfs(1,01,0);
    res[1] = root_depth;
    DFS(1,01,n);
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}