#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll globalN;
const ll inv2 = 500000004;
vector<vector<ll>> dp;
ll mod = 1e9+7;
ll recurence(ll curr, ll currSum, ll idealSum){
    //base case
    if(curr==0){
        if(currSum==idealSum){
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[curr][currSum]!=-1){
        return dp[curr][currSum];
    }
    ll notTake = 0;
    ll take = 0;
    
    //notTake
    notTake = recurence(curr-1,currSum,idealSum)%mod;

    //take
    if(!(currSum+curr>idealSum)){
        take = recurence(curr-1,currSum+curr,idealSum)%mod;
    }
    return dp[curr][currSum] = (take + notTake)%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while (t--) {
        int n;
        cin>>n;
        globalN = n+1;
        
        if((n*(n+1)/2)%2){
            cout<<0<<"\n";
            continue;
        }
        ll idealSum = (n*(n+1)/2)/2;
        dp.resize(n+1,vector<ll>(idealSum+1,0));
        dp[0][idealSum] = 1;        
        for(int curr = 1; curr <= n; curr++){
            for(int currSum = 0; currSum <= idealSum; currSum++){
                ll notTake = dp[curr-1][currSum];
                ll take = 0;

                if(currSum + curr <= idealSum)
                    take = dp[curr-1][currSum + curr];

                dp[curr][currSum] = (notTake + take) % mod;
            }
        }

        const ll inv2 = 500000004;
        cout << (dp[n][0] * inv2) % mod;
    }
}