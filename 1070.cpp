#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;   
    cin>>n;
    vector<int> arr(n+1);
    arr[n/2]=n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION";
        return 0;
    }else{
        if(n%2==0){
            int ptr = 0;
            for(int i=1;i<=n-1;i+=2){
                arr[ptr]=n-i;
                ptr++;
            }
            ptr = n/2+1;
            for(int i=2;i<=n-2;i+=2){
                arr[ptr]=n-i;
                ptr++;
            }
        }else{
            int ptr = 0;
            for(int i=1;i<=n-2;i+=2){
                arr[ptr]=n-i;
                ptr++;
            }
            ptr = n/2+1;
            for(int i=2;i<=n-1;i+=2){
                arr[ptr]=n-i;
                ptr++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}