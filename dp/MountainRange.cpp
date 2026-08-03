#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<pair<ll,int>> valInd(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        valInd[i].first = arr[i];
        valInd[i].second = i;
    }
    stack<ll> st;
    vector<int> nge(n);
    vector<int> pge(n);
    pge[0] = -1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<= arr[i]){
            st.pop();
        }
        if(st.empty()){
            pge[i] = -1;
        }else{
            pge[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    nge[n-1] = -1;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    sort(valInd.rbegin(),valInd.rend());
    vector<ll> dp(n,0);

    for(int i=0; i<n; i++){
        int idx = valInd[i].second;
        int ngidx = nge[idx];
        int pgidx = pge[idx];
        dp[idx] = 1;
        if(ngidx !=- 1) dp[idx] = max(dp[idx] , dp[ngidx]+1);
        if(pgidx !=- 1) dp[idx]=max(dp[idx],dp[pgidx]+1);
    }
    ll ans = *max_element(dp.begin(),dp.end());
    cout<<ans;
}