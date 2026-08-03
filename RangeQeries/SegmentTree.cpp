#include <bits/stdc++.h>
using namespace std;

vector<int> seg,a;

void build(int i,int l,int r){
    if(l==r){
        seg[i] = a[l];
        return;
    }
    int mid = l+(r-l)/2;
    
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    seg[i] = seg[2*i+1]+ seg[2*i+2];
}

void update(int i,int l,int r,int ind,int val){
    if(l==r){
        seg[i] = val;
        a[ind] = val;
        return;
    }
    int mid = l+(r-l)/2;
    if(ind<=mid){
        update(2*i+1,l,mid,ind,val);
    }else{
        update(2*i+2,mid+1,r,ind,val);
    }
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

int rangeSum(int i,int l,int r,int a,int b){
    if(a<=l && r<=b){
        return seg[i];
    }
    if(r<a || l>b){
        return 0;
    }
    int mid = l+(r-l)/2;
    return rangeSum(2*i+1,l,mid,a,b) + rangeSum(2*i+1,mid+1,r,a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    a = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,0,n-1);


}