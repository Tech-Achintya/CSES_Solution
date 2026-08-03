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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}