#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        arr[i] = {x,y};
    }
    sort(arr.begin(),arr.end(),comp);
    int ans = 1;
    vector<int> temp(n,1);
    for(int i=1;i<n;i++){
        if(arr[i-1].second<=arr[i].first){
            temp[i] = temp[i] + temp[i-1];
        }
        ans = max(ans,temp[i]);
    }   
    cout<<ans;
}