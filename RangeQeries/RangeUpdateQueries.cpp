#include <bits/stdc++.h>
using namespace std;
vector<long long> seg;

void build(int i,int l,int r,vector<int>& arr){
    if(l==r){
        seg[i]=arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*i+1,l,mid,arr);
    build(2*i+2,mid+1,r,arr);
}
long long getValue(int i,int l,int r,int pos){
    if(l==r){
        return seg[i];
    }

    int mid = l+(r-l)/2;

    if(pos<=mid){
        return seg[i] + getValue(2*i+1,l,mid,pos);
    }
    return seg[i] + getValue(2*i+2,mid+1,r,pos);
}
void update(int i,int l,int r,int ul,int ur,int val){
    if(r<ul || l>ur){
        return;
    }
    if(ul<=l && r<=ur){
        seg[i]+=val;
        return;
    }
    int mid = l+(r-l)/2;
    update(2*i+1,l,mid,ul,ur,val);
    update(2*i+2,mid+1,r,ul,ur,val);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    seg.resize(4*n);
    build(0,0,n-1,arr);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b,u;
            cin>>a>>b>>u;
            update(0,0,n-1,a-1,b-1,u);
        }else{
            int k;
            cin>>k;
            cout<<getValue(0,0,n-1,k-1)<<"\n";
        }
    }
 }