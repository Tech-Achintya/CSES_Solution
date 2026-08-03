#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

set<ll> s;
vector<vector<bool>> dp(1e2+1, vector<bool>(1e5+1, false));
void funct(int i,ll sum , int n ,vector<int>& arr){
    //base case 
    if(i==n){
        s.insert(sum);
        return;
    }
    if(dp[i][sum]){
        return;
    }
    //include the element
    funct(i+1,sum+arr[i],n,arr);
    //exclude the element
    funct(i+1,sum,n,arr);
    dp[i][sum]=true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        s.clear();
        funct(0,0,n,arr);
        cout<<s.size()-1<<endl;
        for(int i : s){
            if(i!=0){
                cout<<i<<" ";
            }
        }
    }
}