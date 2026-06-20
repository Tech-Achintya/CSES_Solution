#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<vector<ll>>> dp;
ll funct(int i,int j,int n,vector<int>& arr,int player){
    //base case
    if(i>j){
        return 0;
    }
    if(i==j){
        return player==1?0:arr[i];
    }
    if(dp[i][j][player]!=-1){
        return dp[i][j][player];
    }
    ll takeFirst = -1e9;
    ll takeLast = -1e9;
    if(player==1){
        takeFirst = funct(i+1,j,n,arr,1-player);
        takeLast = funct(i,j-1,n,arr,1-player);
         return dp[i][j][player] = min(takeFirst,takeLast);
    }else{
        takeFirst = arr[i] + funct(i+1,j,n,arr,1-player);
        takeLast = arr[j] + funct(i,j-1,n,arr,1-player);
        return dp[i][j][player] = max(takeFirst,takeLast);
    }
   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int i = 0;
        int j = n-1;
        // dp.resize(n+1, vector<vector<ll>>(n+1, vector<ll>(2, -1)));
        // ll ans = funct(i,j,n,arr,0);
        // cout<<ans;

        dp.resize(n+1, vector<vector<ll>>(n+1, vector<ll>(2, 0)));
        for(int i=0;i<n;i++){
            dp[i][i][0] = arr[i];
            dp[i][i][1] = 0;
        }

        for(int len=2; len<=n; len++){

            for(int i=0; i+len-1<n; i++){

                int j = i + len - 1;

                dp[i][j][1] =
                    min(
                        dp[i+1][j][0],
                        dp[i][j-1][0]
                    );

                dp[i][j][0] =
                    max(
                        arr[i] + dp[i+1][j][1],
                        arr[j] + dp[i][j-1][1]
                    );
            }
        }   
        cout << dp[0][n-1][0];
    }
}
