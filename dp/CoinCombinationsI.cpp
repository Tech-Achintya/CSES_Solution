#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
 
long long solve(int target, vector<long long>& coins,vector<long long>& dp) {
    if (target == 0) return 1;
    if (target < 0) return 0;
      if(dp[target]!=-1){
            return dp[target];
      }
    long long ways = 0;
    for (long long c : coins) {
        if (c <= target) {
            ways = (ways + solve(target - c, coins,dp)) % MOD;
        }
    }
    return dp[target] = ways;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long n, x;
    cin >> n >> x;
    vector<long long> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
 
    vector<long long> dp(x+1,-1);
    cout << solve(x, coins,dp) % MOD <<endl;
    return 0;
}
