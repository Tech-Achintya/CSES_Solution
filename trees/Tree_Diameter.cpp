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


vector<vector<int>> adjList;
int maxLen = 0;
int funct(int node,int par){
    int max1 = 0 ,max2 = 0;
    
    for(auto it :adjList[node]){
        if(it==par) continue;

        int depth = funct(it,node) + 1;
        if(depth>max1){
            max2 = max1;
            max1 = depth;
        }else{
            max2 = depth;
        }
        maxLen = max(maxLen,max1 + max2);
    }
    return max(max1,max2);
}

int main(){
    FAST
    int n;
    cin>>n;

    adjList.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    funct(1,-1);
    cout<<maxLen<<"\n";
    return 0;
}