#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> arr(n);
    vector<pair<ll,ll>> valInd(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        valInd[i].first = arr[i];
        valInd[i].second = i;
    }   
    
}