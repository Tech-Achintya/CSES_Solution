#include <bits/stdc++.h>
using namespace std;
//         vector<long long> seg;
//         vector<int> a;

//         void build(int i,int l,int r){
//             if(l==r){
//                 seg[i] = a[l];       
//                             return;
//                  }
//             int mid = l+(r-l)/2;
//             build(2*i+1,l,mid);
//             build(2*i+2,mid+1,r);
//             seg[i] = seg[2*i+1]+seg[2*i+2];
//         }
//         long long query(int i,int l,int r,int ql,int qr){
//             if(ql<=l && r<=qr){
//                 return seg[i];
//             }
//             if(r<ql || l>qr){
//                 return 0;
//             }
//             int mid = l+(r-l)/2;                 ---------->>>> Solution without coordinate compression
//             return query(2*i+1,l,mid,ql,qr) + query(2*i+2,mid+1,r,ql,qr);
//         }
//         void update(int i,int l,int r,int num,int val){
//             if(l==r){
//                 seg[i]+=val;
//                 a[l]+=val;
//                 return;
//             }
//             int mid = l+(r-l)/2;
//             if(mid>=num){
//                 update(2*i+1,l,mid,num,val);
//             }else{
//                 update(2*i+2,mid+1,r,num,val);
//             }
//             seg[i] = seg[2*i+1] + seg[2*i+2];
//         }
//         int main() {
//             ios::sync_with_stdio(false);
//             cin.tie(nullptr);
//             int n,q;
//             cin>>n>>q;
//             vector<int> arr(n);
//             int maxi = 0;
//             for(int i=0;i<n;i++){
//                 cin>>arr[i];
//                 maxi = max(maxi,arr[i]);
//             }
//             vector<int> temp(maxi+1);
//             for(int i=0;i<n;i++){
//                 temp[arr[i]]++;
//             }
//             a = temp;
//             seg.resize(4*(maxi+1));
//             build(0,0,maxi);
//             while(q--){
//                 char type;
//                 cin>>type;
//                 if(type=='!'){
//                     int k,x;
//                     cin>>k>>x;
//                     update(0,0,maxi,arr[k-1],-1);
//                     update(0,0,maxi,x,+1);
//                     arr[k-1] = x;
//                 }else{
//                     int x,y;
//                     cin>>x>>y;
//                     cout<<query(0,0,maxi,x,y)<<"\n";
//                 }
//             }
//             return 0;
// }

class SegmentTree{
    private:
    int n;
    vector<long long> seg;
    void update(int i,int l,int r,int pos,int delta){
        if(l==r){
            seg[i]+=delta;
            return;
        }
        int mid = l+(r-l)/2;
        if(pos<=mid){
           update(2*i+1,l,mid,pos,delta);
        }else{
            update(2*i+2,mid+1,r,pos,delta);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    int query(int i,int l,int r,int ql,int qr){
        if(r<ql || qr<l){
            return 0;
        }
        if(ql<=l && r<=qr){
            return seg[i];
        }
        int mid = l+(r-l)/2;
        return query(2*i+1,l,mid,ql,qr) +query(2*i+2,mid+1,r,ql,qr);
    }
    public:
    SegmentTree(int size){
        seg.resize(4*size);
        n = size;
    }
    void add(int pos,int delta){
        update(0,0,n-1,pos,delta);
    }
    int rangeSum(int ql,int qr){
        return query(0,0,n-1,ql,qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n,q;
    cin>>n>>q;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[i]=x;
    }
    vector<tuple<char,int,int>> quries;
    vector<int> allValues;
    allValues.reserve(n+2*q);
    for(int i=0;i<n;i++){
        allValues.push_back(p[i]);
    }
    for(int i=0;i<q;i++){
        char type;
        cin>>type;
        if(type=='!'){
            int k,x;
            cin>>k>>x;
            quries.push_back({type,k,x});
            allValues.push_back(x);
        }else{
            int a,b;
            cin>>a>>b;
            quries.push_back({type,a,b});
            allValues.push_back(a);
            allValues.push_back(b);
        }
    }
    //coordinate Compresion
    sort(allValues.begin(),allValues.end());
    allValues.erase(unique(allValues.begin(),allValues.end()),allValues.end());
    auto getId = [&](int x){
        return int(lower_bound(allValues.begin(),allValues.end(),x)-allValues.begin());
    };
    int max_id = allValues.size();
    SegmentTree st(max_id);  
    //filling segment tree (build) with new copies
    // making another vector of slaryId
    vector<int> salary_id(n);
    for(int i=0;i<n;i++){
        salary_id[i] = getId(p[i]);
        st.add(salary_id[i],1);
    }
    //process query
    for(auto [type,a,b] : quries){
        if(type=='!'){
            int k = a; int x = b;
            int newId = getId(x);
            st.add(salary_id[k-1],-1);
            salary_id[k-1] = newId;
            st.add(newId,+1);
        }else{
            int x = getId(a);
            int y = getId(b);
            cout<<st.rangeSum(x,y)<<"\n";
        }
    }
    return 0;
}