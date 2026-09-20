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
// const int MAX = 1e4;
string toBinaryString(int n, int width = -1) {
    // handle zero explicitly
    if(n == 0) {
        return (width == -1 ? "0" : string(width, '0'));
    }

    string s;
    while(n > 0) {
        s.push_back((n % 2) + '0'); // add '0' or '1'
        n /= 2;
    }
    reverse(s.begin(), s.end());

    // pad with leading zeros if width is specified
    if(width != -1 && (int)s.size() < width) {
        s = string(width - s.size(), '0') + s;
    }

    return s;
}
int main(){
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;

        adjList[u].push_back(v);
    }
    
    int MAX = (1<<n);
    vector<vector<ll>> dp(MAX+1,vector<ll> (n+1,0));
    dp[1][0] = 1;
    int iterations = 0;
    for(int mask = 0;mask<MAX;mask++){
        iterations++;
        cout<<"Iteration : "<<iterations<<" mask : "<< mask <<"binrary "<<toBinaryString(mask)<<"\n";
        for(int endCity = 0;endCity<n;endCity++){
            cout<<"pick end city as : endcity "<<endCity<<"binrary "<<toBinaryString(endCity)<<"\n";
            if(!(mask & (1<<endCity))) continue;
            if(dp[mask][endCity]==0) continue;
            for(auto neigh : adjList[endCity]){
                cout<<" neighbour for : endcity "<<"binrary "<<toBinaryString(endCity)<<" is "<<" neigh : "<<toBinaryString(neigh)<<"\n";
                if(mask & (1<<neigh)) continue;
                int nextMask = mask | (1<<neigh);
                dp[nextMask][neigh] = (dp[nextMask][neigh] +  dp[mask][endCity]) %MOD;
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    cout<<dp[MAX-1][n-1]%MOD;
    return 0;
}