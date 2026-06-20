#include <bits/stdc++.h>
using namespace std;

vector<int> seg, arr;

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
int rangeMin(int i,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr){
        return seg[i];
    }
    if(r<ql || l>qr){
        return 1e9;
    }
    int mid = l+(r-l)/2;
    return min(rangeMin(2*i+1,l,mid,ql,qr),rangeMin(2*i+2,mid+1,r,ql,qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;int q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    arr=a;
    seg.resize(4*n);
    build(0,0,n-1);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<rangeMin(0,0,n-1,a-1,b-1)<<"\n";
    }
}