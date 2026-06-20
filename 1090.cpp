#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i = 0;
    int j = n-1;
    sort(arr.begin(),arr.end());
    int cnt = 0;
    while(i<=j){
        if(i==j){
            cnt++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]<=x){
            cnt++;
            i++;
            j--;
        }else{
            cnt++;
            j--;
        }
    }
    cout<<cnt<<"\n";
}
