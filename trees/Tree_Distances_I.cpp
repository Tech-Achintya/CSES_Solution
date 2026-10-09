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

// idea is to find the farthest node from root from dfs and then on that node again apply dfs and get the farthest node that distance
// will be the diameter and that two nodes are the farthest nodes

// with this approch we can solve the application based question of tree diameter
vector<vector<ll>> adjList;

void funct(ll node,ll par,ll depth,vector<ll>& nums){
    nums[node] = depth;
    for(auto it : adjList[node]){
        if(it==par) continue;
        funct(it,node,depth+1,nums);
    }
}

int main(){
    FAST
    ll n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    adjList.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    vector<ll> distanceFomRoot(n+1);
    funct(1,-1,0,distanceFomRoot);
    ll node = -1;
    ll maxDist = 0;
    for(int i=1;i<=n;i++){
        if(maxDist<distanceFomRoot[i]){
            maxDist = distanceFomRoot[i];
            node = i;
        }
    }
    vector<ll> distanceFirstMaxLeaf(n+1);
    funct(node,-1,0,distanceFirstMaxLeaf);
    node = -1;
    maxDist = 0;
    for(int i=1;i<=n;i++){
        if(maxDist<distanceFirstMaxLeaf[i]){
            maxDist = distanceFirstMaxLeaf[i];
            node = i;
        }
    }
    vector<ll> distanceSecondMaxLeaf(n+1);
    funct(node,-1,0,distanceSecondMaxLeaf);

    vector<ll> ans(n+1);
    for(int i=1;i<=n;i++){
        ans[i] = max(distanceFirstMaxLeaf[i],distanceSecondMaxLeaf[i]);
    }
    for(auto it : ans){
        if(it==0) continue;
        cout<<it<<" ";
    }
    return 0;
}