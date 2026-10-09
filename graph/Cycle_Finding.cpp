#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef tuple<int,int,int> edge;
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


int main(){
    FAST
    int n,m;
    cin>>n>>m;
    vector<edge> arr(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr[i] = {u,v,w};
    }
    vector<ll> dist(n+1,0);
    vector<int> relaxant(n+1,-1);
    //u->v
    // dist[u] + w <dist[v]
    for(int i=0;i<n-1;i++){
        for(auto &[u,v,w] : arr){
            if(dist[u] + w <dist[v]){
                relaxant[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }
    bool isNeg = false;
    int lastNodeRelaxed = -1;
    for(auto &[u,v,w] : arr){
        if(dist[u] + w < dist[v]){
            isNeg = true;
            relaxant[v] = u;
            lastNodeRelaxed = v;
            break;
        }
    }
    if(!isNeg){
        cout<<"NO";
    }else{

        for(int i=0;i<n;i++){
            lastNodeRelaxed = relaxant[lastNodeRelaxed];
        }

        vector<int> cycle;
        int node = lastNodeRelaxed;
        do {
            cycle.push_back(node);
            node = relaxant[node];
        } while (node != lastNodeRelaxed);
        cycle.push_back(cycle[0]);
        reverse(all(cycle));
        cout<<"YES\n";
        for(auto n : cycle){
            cout<<n<<" ";
        }
    }

    return 0;
}