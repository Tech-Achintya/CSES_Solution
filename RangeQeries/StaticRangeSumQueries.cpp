#include <bits/stdc++.h>
using namespace std;

// vector<int> seg;

// void build(int i,int l,int r,vector<int> &arr){
//     if(l==r){
//         seg[i]=arr[i];
//     }
//     int mid = l+(r-l)/2;
//     build(2*i+1,l,mid,arr);
//     build(2*i+2,mid+1,r,arr);
//     seg[i] = seg[2*i+1] + seg[2*i+2];
// }

// int rangeQuery(int i,int l,int r,int ql,int qr,vector<int> &arr){

// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // seg.resize(4*n);
    vector<long long> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        long long i = l-2<0?0:prefixSum[l-2];
        cout<<prefixSum[r-1]-i<<"\n";
    }
    return 0;
}
// 3 2 4 5 1 1 5 3
// 3 5 9 14 15 16 21 24
// 2 4