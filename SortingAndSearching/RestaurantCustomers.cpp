#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    while(n--){
        int x,y;
        cin>>x>>y;
        arr.push_back({x,+1});
        arr.push_back({y,-1});
    }
    sort(arr.begin(),arr.end());
    int ans = arr[0].second;
    for(int i=1;i<arr.size();i++){
        arr[i].second = arr[i].second + arr[i-1].second;
        ans = max(ans,arr[i].second);
    }
    cout<<ans;
}