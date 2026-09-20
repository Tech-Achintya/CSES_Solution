// CSES 1673 - High Score  (ACCEPTED)
// Idea: Bellman-Ford that MAXIMISES the score (no negation).
//   1) n-1 rounds of relaxation  -> correct answer if there is no positive cycle
//   2) one extra round           -> any edge that still improves has its head "affected" by a positive cycle
//   3) BFS (queue) from those nodes -> if n is reachable from any affected node, answer is -1
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
const ll NEG = LLONG_MIN;   // means "node not reachable from 1 yet"

struct Node{
    ll u; 
    ll v;
    ll w;
};
int main(){
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> adjList(n+1);   // normal graph, only used for the BFS at the end
    vector<Node> edgeInfo(m);          // edge list, used by Bellman-Ford
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edgeInfo[i].u = u;
        edgeInfo[i].v = v;
        edgeInfo[i].w = w;
        adjList[u].push_back(v);
    }
    vector<ll> dist(n+1,NEG);
    dist[1] = 0;

    // Step 1: n-1 rounds of relaxation (maximising, so use '>')
    for(int k=0;k<n-1;k++){
        for(auto info : edgeInfo){
            ll u = info.u; ll v = info.v; ll w = info.w; 
            if(dist[u]==NEG) continue;   // IMPORTANT: never relax from a node unreachable from 1
            if(dist[u] + w > dist[v]) dist[v] = dist[u] + w;
        }
    }

    // Step 2: n-th round, only DETECT (don't update dist).
    // An edge that still improves means v is affected by a positive cycle -> push v in queue.
    // dist[u]!=NEG also guarantees the cycle is reachable from 1.
    queue<int> q;
    vector<bool> vis(n+1,false);
    for(auto info : edgeInfo){
        ll u = info.u; ll v = info.v; ll w = info.w; 
        if(dist[u]==NEG) continue;
        if(dist[u] + w > dist[v] && !vis[v]){
            q.push(v);
            vis[v] = true;
        }
    }

    // Step 3: BFS from all affected nodes; everything reachable from them is also unbounded
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto it : adjList[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }

    if(vis[n]){
        cout<<-1;          // positive cycle on the way 1 -> n, score can be infinite
    }else{
        cout<<dist[n];     // normal max score
    }

    return 0;
}