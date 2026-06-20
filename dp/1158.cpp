#include <bits/stdc++.h>
using namespace std;


long long solve(long long i,int moneyLeft,vector<long long> &price,vector<long long> &pages,vector<vector<long long>> &memo){
    if(i==price.size()){
        return 0;
    }
    if(memo[i][moneyLeft]!=-1){
        return memo[i][moneyLeft];
    }
    //pick
    long long pick = -1e9;
    if(moneyLeft>=price[i]){
        pick = pages[i]+solve(i+1,moneyLeft-price[i],price,pages,memo);
    }
    long long notPick = solve(i+1,moneyLeft,price,pages,memo);
    return memo[i][moneyLeft] = max(notPick,pick);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,x;
    cin>>n>>x;
    vector<long long> price(n);
    vector<long long> pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<long long> curr(x+1,0);
    vector<long long> prev(x+1,0);
    for(int j=0;j<=x;j++){
        if(j>=price[0]){
            prev[j] = pages[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            long long pick = -1e6;
            if(j>=price[i]){
                pick = pages[i]+prev[j-price[i]];
            }
            long long notPick = prev[j];
            curr[j] = max(notPick,pick);
        }
        prev = curr;
    }
    cout<<prev[x]<<"\n";
}