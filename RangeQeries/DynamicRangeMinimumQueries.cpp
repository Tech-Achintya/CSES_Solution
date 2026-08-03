#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg;
vector<int> arr;

void build(int i,int l,int r){
    if(l==r){
        seg[i] = arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    seg[i] = min(seg[2*i+1],seg[2*i+2]);
}

void update(int i,int l,int r,int ind,int val){
    if(l==r){
        seg[i] = val;
        arr[ind] = val;
        return;
    }
    int mid = l+(r-l)/2;
    if(ind<=mid){
        update(2*i+1,l,mid,ind,val);
    }else{
        update(2*i+2,mid+1,r,ind,val);
    }
    seg[i] = min(seg[2*i+1],seg[2*i+2]);
}

ll rangeMin(int i,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr){
        return seg[i];
    }
    if(r<ql || l>qr){
        return 1e9;
    }
    int mid = l+(r-l)/2;
    return min(rangeMin(2*i+1,l,mid,ql,qr),rangeMin(2*i+2,mid+1,r,ql,qr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int q;
    cin>>q;
    arr = vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    seg.resize(4*n);
    build(0,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k,u;
            cin>>k>>u;
            update(0,0,n-1,k-1,u);
        }else{
            int a,b;
            cin>>a>>b;
            cout<< rangeMin(0,0,n-1,a-1,b-1)<<"\n";
        }
    }
}