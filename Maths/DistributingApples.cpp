#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> fact;
ll mod = 1e9+7;
ll maxVal = 10000000+5;
void preComputeFact(){
    fact.resize(maxVal);
    fact[0] = 1;
    for(int i=1;i<maxVal;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}
ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {         
            result = (result * base)%mod;
        }
        base = (base * base)%mod;         
        exp >>= 1;              
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    n--;
    preComputeFact();
    ll ans = fact[m+n];
    ans = (ans * power(fact[m],mod-2)%mod)%mod;
    ans = (ans * power(fact[n],mod-2)%mod)%mod;
    cout<<ans<<"\n";
}