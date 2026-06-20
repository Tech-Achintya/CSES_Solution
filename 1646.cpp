// 3 2 4 5 1 1 5 3
// 3 5 9 14 15 16 21 24
// [2,4]->[1,4]-[1,1] = 14-3

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;long long q;
    cin>>n>>q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //cal prefixSum
    for(int i=1;i<n;i++){
        arr[i] = arr[i]+arr[i-1];
    }
    while(q--){
        int ind1;int ind2;
        cin>>ind1;
        cin>>ind2;
        long long a = arr[ind2-1];
        long long b = ind1==1?0:arr[ind1-2];
        
        cout<<a-b<<" ";
    }

}