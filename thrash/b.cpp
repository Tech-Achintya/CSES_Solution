#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n,k,m;
        cin >> n >> k >>m;
        if(k > m){
            cout << "NO\n";
            continue;
        }else{
            cout<<"Yes"<<"\n";
            int i =0;
            while(i<n){
                if(i<k){
                    if(i==k-1){
                        cout<<m-(k-1)<<" ";
                    }else{
                        cout<<1<<" ";
                    }
                }else{
                    cout<<1<<" ";
                }
                i++;
            }
            cout<<"\n";
        }
    }
}