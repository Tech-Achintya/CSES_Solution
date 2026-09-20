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

//basic Dijskta 

int main(){
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjList(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
    }
    vector<ll> dist(n+1, LLONG_MAX);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    dist[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        ll currentDist = it.first;
        int node = it.second;
        if(currentDist!=dist[node]) continue; // major optimization
        for(auto neighbour : adjList[node]){
            int newNode = neighbour.first;
            ll newDist = neighbour.second + currentDist;
            if(newDist < dist[newNode]){
                dist[newNode] = newDist;
                q.push({newDist, newNode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}