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
 
struct Node { 
    ll weight; 
    int u; 
    bool isUsed; 
 
    bool operator>(const Node& other) const { 
        return weight > other.weight; 
    } 
}; 
 
int main(){ 
    FAST 
    int n,m; 
    cin>>n>>m; 
    vector<vector<pair<int,int>>> adjList(n+1); 
    for(int i=0;i<m;i++){ 
        int u,v,w; cin>>u>>v>>w; 
        adjList[u].push_back({v,w}); 
    } 

    vector<vector<ll>> dist(n+1,vector<ll>(2,INF)); // FIX
    dist[1][0] = 0; 
    priority_queue<Node , vector<Node> ,greater<Node>> pq; 
    pq.push({0,1,false}); 

    while (!pq.empty()){ 
        auto it = pq.top(); 
        pq.pop(); 
        int node = it.u; 
        ll weight = it.weight; // FIX
        bool isUsed = it.isUsed; 

        if(weight != dist[node][isUsed]){ 
            continue; 
        }  

        for(auto neigh : adjList[node]){ 
            int neighNode = neigh.first; 
            int neighWeight = neigh.second; // FIX
            ll newCost = neighWeight + weight; 
 
            // node(current) doesnt used his coupon to travel to neighNode 
            if(dist[neighNode][isUsed]>newCost){ 
                dist[neighNode][isUsed] = newCost; 
                pq.push({newCost,neighNode,isUsed}); 
            } 

            if(!isUsed){ 
                newCost = weight + (neighWeight/2); 
                if(dist[neighNode][1]>newCost){ 
                    dist[neighNode][1] = newCost; 
                    pq.push({newCost,neighNode,true}); 
                } 
            } 
        } 
    } 

    cout<<dist[n][1]; 
     
    return 0; 
}