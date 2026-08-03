#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Project{
    int start; int end; int profit;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<Project> projs(n);
    vector<int> allEnd(n);
    for(int i = 0;i<n;i++){
        // int strt; int end; int val;
        cin>>projs[i].start>>projs[i].end>>projs[i].profit;
    }
    vector<ll> dp(n+1);
    
    sort(projs.begin(),projs.end(),[](Project &a,Project &b){
        return a.end < b.end;
    });
    for(int i=0;i<n;i++){
        allEnd[i] = projs[i].end;
    }

    dp[0] = projs[0].profit;
    for(int i=1;i<n;i++){
        ll take = projs[i].profit;
        ll skip = dp[i-1];
        int ind = lower_bound(allEnd.begin(),allEnd.end(),projs[i].start) - allEnd.begin()-1;
        if(ind>=0){
            take+=dp[ind];
        }        
        dp[i] = max(skip,take);
    }
    cout<<dp[n-1];
}