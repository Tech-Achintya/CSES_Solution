#include <bits/stdc++.h>
using namespace std;

vector<int> segmentTrees;

void built(int i,int left,int right,vector<int> &arr){
    if(left==right){
        segmentTrees[i] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    built(2*i+1,left,mid,arr);
    built(2*i+2,mid+1,right,arr);
    segmentTrees[i] = segmentTrees[2*i+1]+segmentTrees[2*i+2];

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    segmentTrees.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    built(0,0,n-1,arr);
    for(int i=0;i<segmentTrees.size();i++){
        cout<<segmentTrees[i]<<" ";
    }
}