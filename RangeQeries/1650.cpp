#include <bits/stdc++.h>
using namespace std;

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
    vector<long long> prefixArr(n);
    prefixArr[0] = arr[0];
    for(int i =1;i<n;i++){
        prefixArr[i] = prefixArr[i-1]^arr[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        long long i = l-2<0?0:prefixArr[l-2];
        cout<<(prefixArr[r-1]^i)<<"\n";
    }
}