#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> num;
vector<vector<vector<vector<long long>>>> dp;
long long dfs(int pos,int tight,int leadingZeros,int prevDigit){
    //base case
    if(pos == num.size()){
        return 1;
    }
    if(dp[pos][tight][leadingZeros][prevDigit+1]!=-1){
        return dp[pos][tight][leadingZeros][prevDigit+1];
    }
    long long count = 0;
    if(tight==1){
        int bounded = num[pos];
        for(int i=0;i<=bounded;i++){   
            if(i==0 && leadingZeros==0){
                count += dfs(pos+1,(i==bounded),0,-1);
                continue;
            }
            if(prevDigit==i) continue;
            count += dfs(pos+1,(i==bounded),1,i);
        }
    }else{
        for(int i=0;i<=9;i++){
            if(i==0 && leadingZeros==0){
                count += dfs(pos+1,0,0,-1);
                continue;
            }
            if(prevDigit==i) continue;
            count += dfs(pos+1,0,1,i);
        }
    }
    return dp[pos][tight][leadingZeros][prevDigit+1] = count;
}
ll solve(ll x){
    if(x==0)
        return 1;
    num.clear();
    while(x>0){
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    int n = num.size();
    dp.assign(n,
    vector<vector<vector<long long>>>(2,
        vector<vector<long long>>(2,
            vector<long long>(11, -1))));
    return dfs(0,1,0,-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b;
    cin >> a >> b;
    if(a==0){
        cout<<solve(b);
    }else{
        cout << solve(b) - solve(a-1);
    }
}