#include <bits/stdc++.h>
using namespace std;

// int funct(int i,int j,vector<int> &nums1,vector<int> &nums2){
//     //base case
//     if(i==nums1.size() || j==nums2.size()){
//         return 0;
//     }
//     int ans1 = 0;
//     if(nums1[i]==nums2[j]){
//         ans1 = 1 + funct(i+1,j+1,nums1,nums2);
//     }
//     int ans2 = funct(i+1,j,nums1,nums2);
//     int ans3 = funct(i,j+1,nums1,nums2);
//     return max({ans1,ans2,ans3});
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    // int res = funct(0,0,nums1,nums2);
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    int i=n;
    int j=m;
    vector<int> seq;
    while(i>0 && j>0){
        if(nums1[i-1]==nums2[j-1]){
            seq.push_back(nums1[i-1]);
            i--;j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    for(int i=seq.size()-1;i>=0;i--){
        cout<<seq[i]<<" ";
    }
        
}