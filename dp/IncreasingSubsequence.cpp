#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void print(const vector<ll>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> temp;
    temp.push_back(arr[0]);
    for(int i= 1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout<<temp.size();
    // int ans =  *max_element(dp.begin(), dp.end());
    // print(dp);
    // cout<<ans;
}  