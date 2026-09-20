#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define ppb pop_back
#define eb emplace_back

#define ff first
#define ss second
#define mp make_pair

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()

const int MOD = 1e9+7;
const int MOD2 = 998244353;
const ll INF = 1e18;

/*==============================*/
/* Fast IO */
/*==============================*/
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/*==============================*/
/* Binary Exponentiation */
/*==============================*/
/* ll binExp(ll a,ll b,ll mod=MOD){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
} */

/*==============================*/
/* Modular Inverse (Fermat) */
/*==============================*/
/* ll modInverse(ll a,ll mod=MOD){
    return binExp(a,mod-2,mod);
} */

/*==============================*/
/* Sieve of Eratosthenes */
/*==============================*/
const int MAXN = 200005;
/* vector<bool> isPrime(MAXN,true);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<MAXN;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    }
} */

/*==============================*/
/* GCD */
/*==============================*/
/*==============================*/
/* LCM */
/*==============================*/
/* ll lcmll(ll a,ll b){
    return (a/gcdll(a,b))*b;
} */

/*==============================*/
/* Print Vector */
/*==============================*/
/*template<typename T>
void printVector(vector<T>& v){
    for(auto x : v) cout << x << " ";
    cout << '\n';
} */

/*==============================*/
/* YES / NO */
/*==============================*/
void YES(){ cout << "YES\n"; }
void NO(){ cout << "NO\n"; }

ll funct(ll n,ll k){
    if(n==1) return 1;

    int evenKills = n/2;
    if(n%2==0){
        if(k<=evenKills){
            return 2*k;
        }

        ll x = funct(n/2,k-evenKills);
        return 2*x-1;
    }
    if(k<=evenKills){
        return 2*k;
    }

    if(k == evenKills+1){
        return 1;
    }
    long long x = funct(n/2,k-evenKills-1);
    return 2*x+1;

}


void solve(){
    ll n,k;
    cin>>n>>k;
    int kthGuyKilled = funct(n,k);
    cout<<kthGuyKilled<<"\n";
}

int main(){
    fastIO();
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}